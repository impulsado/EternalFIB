#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <cstring>
#include <iomanip>
#include <filesystem>

using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;

// Estructura per emmagatzemar informació dels fitxers
struct FileInfo {
    double size_mb;     // Mida del fitxer en MB (sense decimals)
    string filename;    // Nom del fitxer
};

// Nombre de mides de fitxer i repeticions per cada mètode
const int min_size_mb = 1;
const int max_size_mb = 25;
const int repetitions = 5;

// Funció per generar fitxers pseudoaleatoris amb mida entera en MB
bool generate_random_file(const string& filepath, double size_mb) {
    // Convertir MB a bytes
    size_t total_bytes = static_cast<size_t>(size_mb * 1024 * 1024);
    vector<unsigned char> buffer(1024 * 1024); // Buffer de 1 MB

    ofstream outfile(filepath, ios::binary);
    if (!outfile.is_open()) {
        cerr << "No s'ha pogut crear el fitxer: " << filepath << endl;
        return false;
    }

    size_t bytes_written = 0;
    while (bytes_written < total_bytes) {
        size_t bytes_to_write = buffer.size();
        if (bytes_written + bytes_to_write > total_bytes) {
            bytes_to_write = total_bytes - bytes_written;
        }

        // Generar bytes pseudoaleatoris
        if (RAND_bytes(buffer.data(), bytes_to_write) != 1) {
            cerr << "Error generant bytes aleatoris per al fitxer: " << filepath << endl;
            outfile.close();
            return false;
        }
        outfile.write(reinterpret_cast<char*>(buffer.data()), bytes_to_write);
        bytes_written += bytes_to_write;
    }

    outfile.close();
    return true;
}

// Funció per encriptar utilitzant AES-256-CBC amb la interfície EVP
bool encrypt_aes(const string& input_filepath, const string& output_filepath, unsigned char* key, unsigned char* iv) {
    ifstream infile(input_filepath, ios::binary);
    if (!infile.is_open()) {
        cerr << "No s'ha pogut obrir el fitxer d'entrada per AES: " << input_filepath << endl;
        return false;
    }

    ofstream outfile(output_filepath, ios::binary);
    if (!outfile.is_open()) {
        cerr << "No s'ha pogut crear el fitxer de sortida per AES: " << output_filepath << endl;
        infile.close();
        return false;
    }

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        cerr << "Error creant el context EVP per AES." << endl;
        infile.close();
        outfile.close();
        return false;
    }

    // Inicialitzar l'encriptació AES-256-CBC
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key, iv) != 1) {
        cerr << "Error inicialitzant l'encriptació AES." << endl;
        EVP_CIPHER_CTX_free(ctx);
        infile.close();
        outfile.close();
        return false;
    }

    const size_t buffer_size = 1024 * 16; // 16 KB
    vector<unsigned char> in_buffer(buffer_size);
    vector<unsigned char> out_buffer(buffer_size + EVP_CIPHER_block_size(EVP_aes_256_cbc()));
    int out_len;

    while (infile.good()) {
        infile.read(reinterpret_cast<char*>(in_buffer.data()), buffer_size);
        streamsize bytes_read = infile.gcount();
        if (bytes_read > 0) {
            // Encriptar dades
            if (EVP_EncryptUpdate(ctx, out_buffer.data(), &out_len, in_buffer.data(), bytes_read) != 1) {
                cerr << "Error durant EVP_EncryptUpdate per AES." << endl;
                EVP_CIPHER_CTX_free(ctx);
                infile.close();
                outfile.close();
                return false;
            }
            outfile.write(reinterpret_cast<char*>(out_buffer.data()), out_len);
        }
    }

    // Finalitzar l'encriptació
    if (EVP_EncryptFinal_ex(ctx, out_buffer.data(), &out_len) != 1) {
        cerr << "Error durant EVP_EncryptFinal_ex per AES." << endl;
        EVP_CIPHER_CTX_free(ctx);
        infile.close();
        outfile.close();
        return false;
    }
    outfile.write(reinterpret_cast<char*>(out_buffer.data()), out_len);

    // Neteja
    EVP_CIPHER_CTX_free(ctx);
    infile.close();
    outfile.close();
    return true;
}

// Funció per generar parell de claus RSA utilitzant EVP_PKEY
EVP_PKEY* generate_rsa_keypair(int bits = 2048) {
    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, nullptr);
    if (!ctx) {
        cerr << "Error creant el context EVP_PKEY per RSA." << endl;
        return nullptr;
    }

    if (EVP_PKEY_keygen_init(ctx) <= 0) {
        cerr << "Error inicialitzant la generació de claus RSA." << endl;
        EVP_PKEY_CTX_free(ctx);
        return nullptr;
    }

    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, bits) <= 0) { // Establir la mida de la clau RSA
        cerr << "Error establint la mida de la clau RSA." << endl;
        EVP_PKEY_CTX_free(ctx);
        return nullptr;
    }

    EVP_PKEY* pkey = nullptr;
    if (EVP_PKEY_keygen(ctx, &pkey) <= 0) {
        cerr << "Error generant el parell de claus RSA." << endl;
        EVP_PKEY_CTX_free(ctx);
        return nullptr;
    }

    EVP_PKEY_CTX_free(ctx);
    return pkey;
}

// Funció per encriptar utilitzant RSA amb la interfície EVP
bool encrypt_rsa(const string& input_filepath, const string& output_filepath, EVP_PKEY* pkey) {
    ifstream infile(input_filepath, ios::binary);
    if (!infile.is_open()) {
        cerr << "No s'ha pogut obrir el fitxer d'entrada per RSA: " << input_filepath << endl;
        return false;
    }

    ofstream outfile(output_filepath, ios::binary);
    if (!outfile.is_open()) {
        cerr << "No s'ha pogut crear el fitxer de sortida per RSA: " << output_filepath << endl;
        infile.close();
        return false;
    }

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    if (!ctx) {
        cerr << "Error creant el context EVP_PKEY per RSA." << endl;
        infile.close();
        outfile.close();
        return false;
    }

    if (EVP_PKEY_encrypt_init(ctx) <= 0) {
        cerr << "Error inicialitzant l'encriptació RSA." << endl;
        EVP_PKEY_CTX_free(ctx);
        infile.close();
        outfile.close();
        return false;
    }

    // Establir el padding RSA OAEP
    if (EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING) <= 0) {
        cerr << "Error establint el padding RSA." << endl;
        EVP_PKEY_CTX_free(ctx);
        infile.close();
        outfile.close();
        return false;
    }

    // Determinar la mida màxima de chunk per a l'encriptació
    size_t key_size = EVP_PKEY_size(pkey);
    size_t max_chunk_size = key_size - 2 * 20 - 2; // SHA-1 és assumit amb hash_len = 20

    vector<unsigned char> in_buffer(max_chunk_size);
    vector<unsigned char> out_buffer(key_size);
    size_t out_len;

    while (infile.good()) {
        infile.read(reinterpret_cast<char*>(in_buffer.data()), max_chunk_size);
        size_t bytes_read = infile.gcount();
        if (bytes_read > 0) {
            // Encriptar dades
            if (EVP_PKEY_encrypt(ctx, out_buffer.data(), &out_len, in_buffer.data(), bytes_read) <= 0) {
                cerr << "Error encriptant amb RSA: " << ERR_error_string(ERR_get_error(), nullptr) << endl;
                EVP_PKEY_CTX_free(ctx);
                infile.close();
                outfile.close();
                return false;
            }
            outfile.write(reinterpret_cast<char*>(out_buffer.data()), out_len);
        }
    }

    // Neteja
    EVP_PKEY_CTX_free(ctx);
    infile.close();
    outfile.close();
    return true;
}

int main() {
    // Inicialitzar OpenSSL
    OPENSSL_init_crypto(0, nullptr);
    ERR_load_crypto_strings();

    // Generar clau AES i IV
    unsigned char aes_key[32]; // 256 bits
    unsigned char aes_iv[16];  // AES_BLOCK_SIZE és 16 bytes
    if (RAND_bytes(aes_key, sizeof(aes_key)) != 1 || RAND_bytes(aes_iv, sizeof(aes_iv)) != 1) {
        cerr << "Error generant la clau AES o IV." << endl;
        return 1;
    }

    // Generar parell de claus RSA
    EVP_PKEY* rsa_pkey = generate_rsa_keypair();
    if (!rsa_pkey) {
        cerr << "Error generant el parell de claus RSA." << endl;
        return 1;
    }

    // Crear una carpeta temporal
    string temp_dir = "temp_files";
    try {
        if (!fs::create_directory(temp_dir)) {
            cerr << "No s'ha pogut crear la carpeta temporal." << endl;
            EVP_PKEY_free(rsa_pkey);
            return 1;
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Error creant la carpeta temporal: " << e.what() << endl;
        EVP_PKEY_free(rsa_pkey);
        return 1;
    }

    // Obrir fitxer CSV per guardar els resultats
    ofstream csv_file("dades.csv");
    if (!csv_file.is_open()) {
        cerr << "No s'ha pogut crear el fitxer CSV per als resultats." << endl;
        fs::remove_all(temp_dir);
        EVP_PKEY_free(rsa_pkey);
        return 1;
    }

    // Escriure encapçalaments al CSV
    csv_file << "Metode,Mida_MB,Repeticio,Temps_Segons\n";

    // Iterar sobre cada mida de fitxer des de 1MB fins a 25MB
    for (int size_mb = min_size_mb; size_mb <= max_size_mb; ++size_mb) {
        string filename = temp_dir + "/file_" + to_string(size_mb) + "MB.bin";

        // Generar el fitxer si no existeix
        if (!generate_random_file(filename, static_cast<double>(size_mb))) {
            cerr << "Fallo al generar el fitxer: " << filename << endl;
            csv_file.close();
            fs::remove_all(temp_dir);
            EVP_PKEY_free(rsa_pkey);
            return 1;
        }
        cout << "Fitxer generat: " << filename << " (Mida: " << size_mb << " MB)" << endl;

        // Realitzar les repeticions per aquesta mida de fitxer
        for (int rep = 1; rep <= repetitions; ++rep) {
            // Encriptació AES-256
            string output_filename_aes = temp_dir + "/aes_" + to_string(size_mb) + "MB_enc_" + to_string(rep) + ".bin";
            unsigned char iv_copy[16];
            memcpy(iv_copy, aes_iv, 16); // Copiar IV per cada encriptació

            auto start_aes = high_resolution_clock::now();
            if (!encrypt_aes(filename, output_filename_aes, aes_key, iv_copy)) {
                cerr << "Error encriptant amb AES en fitxer " << filename << " (Mida " << size_mb << "MB), repetició " << rep << endl;
                csv_file.close();
                fs::remove_all(temp_dir);
                EVP_PKEY_free(rsa_pkey);
                return 1;
            }
            auto end_aes = high_resolution_clock::now();
            duration<double> elapsed_aes = end_aes - start_aes;

            // Escriure resultat AES al CSV
            csv_file << "AES-256," << size_mb << "," << rep << "," << fixed << setprecision(6) << elapsed_aes.count() << "\n";

            cout << "AES-256: Fitxer " << filename << " (Mida " << size_mb << "MB), Repetició " << rep << ", Temps: " << elapsed_aes.count() << " segons." << endl;

            // Encriptació RSA-256
            string output_filename_rsa = temp_dir + "/rsa_" + to_string(size_mb) + "MB_enc_" + to_string(rep) + ".bin";

            auto start_rsa = high_resolution_clock::now();
            if (!encrypt_rsa(filename, output_filename_rsa, rsa_pkey)) {
                cerr << "Error encriptant amb RSA en fitxer " << filename << " (Mida " << size_mb << "MB), repetició " << rep << endl;
                csv_file.close();
                fs::remove_all(temp_dir);
                EVP_PKEY_free(rsa_pkey);
                return 1;
            }
            auto end_rsa = high_resolution_clock::now();
            duration<double> elapsed_rsa = end_rsa - start_rsa;

            // Escriure resultat RSA al CSV
            csv_file << "RSA-256," << size_mb << "," << rep << "," << fixed << setprecision(6) << elapsed_rsa.count() << "\n";

            cout << "RSA-256: Fitxer " << filename << " (Mida " << size_mb << "MB), Repetició " << rep << ", Temps: " << elapsed_rsa.count() << " segons." << endl;
        }
    }

    // Neteja: tancar el fitxer CSV i eliminar la carpeta temporal
    csv_file.close();
    try {
        fs::remove_all(temp_dir);
        cout << "Carpeta temporal eliminada: " << temp_dir << endl;
    } catch (const fs::filesystem_error& e) {
        cerr << "Error eliminant la carpeta temporal: " << e.what() << endl;
    }

    // Neteja de recursos d'OpenSSL
    EVP_PKEY_free(rsa_pkey);
    EVP_cleanup();
    CRYPTO_cleanup_all_ex_data();
    ERR_free_strings();

    cout << "Estudi completat. Resultats guardats en 'dades.csv'." << endl;
    return 0;
}