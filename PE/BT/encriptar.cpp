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

using namespace std;
using namespace std::chrono;

// Tamaños de los archivos en MB
const vector<size_t> file_sizes_mb = {1, 5, 10, 50, 100};
const int repetitions = 10;

// Función para generar archivos pseudoaleatorios
bool generate_random_file(const string& filename, size_t size_mb) {
    size_t total_bytes = size_mb * 1024 * 1024;
    vector<unsigned char> buffer(1024 * 1024); // 1 MB buffer

    ofstream outfile(filename, ios::binary);
    if (!outfile.is_open()) {
        cerr << "No se pudo crear el archivo: " << filename << endl;
        return false;
    }

    for (size_t i = 0; i < size_mb; ++i) {
        if (RAND_bytes(buffer.data(), buffer.size()) != 1) {
            cerr << "Error generando bytes aleatorios para el archivo: " << filename << endl;
            outfile.close();
            return false;
        }
        outfile.write(reinterpret_cast<char*>(buffer.data()), buffer.size());
    }

    outfile.close();
    return true;
}

// Función para encriptar usando AES-256-CBC con la interfaz EVP
bool encrypt_aes(const string& input_filename, const string& output_filename, unsigned char* key, unsigned char* iv) {
    ifstream infile(input_filename, ios::binary);
    if (!infile.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada para AES: " << input_filename << endl;
        return false;
    }

    ofstream outfile(output_filename, ios::binary);
    if (!outfile.is_open()) {
        cerr << "No se pudo crear el archivo de salida para AES: " << output_filename << endl;
        infile.close();
        return false;
    }

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        cerr << "Error creando el contexto EVP para AES." << endl;
        infile.close();
        outfile.close();
        return false;
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key, iv) != 1) {
        cerr << "Error inicializando el cifrado AES." << endl;
        EVP_CIPHER_CTX_free(ctx);
        infile.close();
        outfile.close();
        return false;
    }

    const size_t buffer_size = 1024 * 16;
    vector<unsigned char> in_buffer(buffer_size);
    vector<unsigned char> out_buffer(buffer_size + EVP_CIPHER_block_size(EVP_aes_256_cbc()));
    int out_len;

    while (infile.good()) {
        infile.read(reinterpret_cast<char*>(in_buffer.data()), buffer_size);
        streamsize bytes_read = infile.gcount();
        if (bytes_read > 0) {
            if (EVP_EncryptUpdate(ctx, out_buffer.data(), &out_len, in_buffer.data(), bytes_read) != 1) {
                cerr << "Error durante EVP_EncryptUpdate para AES." << endl;
                EVP_CIPHER_CTX_free(ctx);
                infile.close();
                outfile.close();
                return false;
            }
            outfile.write(reinterpret_cast<char*>(out_buffer.data()), out_len);
        }
    }

    if (EVP_EncryptFinal_ex(ctx, out_buffer.data(), &out_len) != 1) {
        cerr << "Error durante EVP_EncryptFinal_ex para AES." << endl;
        EVP_CIPHER_CTX_free(ctx);
        infile.close();
        outfile.close();
        return false;
    }
    outfile.write(reinterpret_cast<char*>(out_buffer.data()), out_len);

    EVP_CIPHER_CTX_free(ctx);
    infile.close();
    outfile.close();
    return true;
}

// Función para generar par de claves RSA usando EVP_PKEY
EVP_PKEY* generate_rsa_keypair(int bits = 2048) {
    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, nullptr);
    if (!ctx) {
        cerr << "Error creando el contexto EVP_PKEY para RSA." << endl;
        return nullptr;
    }

    if (EVP_PKEY_keygen_init(ctx) <= 0) {
        cerr << "Error inicializando la generación de claves RSA." << endl;
        EVP_PKEY_CTX_free(ctx);
        return nullptr;
    }

    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, bits) <= 0) { // Cambiado de EVP_PKEY_CTX_set_rsa_keygen_bits a EVP_PKEY_CTX_set_keygen_bits
        cerr << "Error estableciendo el tamaño de la clave RSA." << endl;
        EVP_PKEY_CTX_free(ctx);
        return nullptr;
    }

    EVP_PKEY* pkey = nullptr;
    if (EVP_PKEY_keygen(ctx, &pkey) <= 0) {
        cerr << "Error generando el par de claves RSA." << endl;
        EVP_PKEY_CTX_free(ctx);
        return nullptr;
    }

    EVP_PKEY_CTX_free(ctx);
    return pkey;
}

// Función para encriptar usando RSA con la interfaz EVP
bool encrypt_rsa(const string& input_filename, const string& output_filename, EVP_PKEY* pkey) {
    ifstream infile(input_filename, ios::binary);
    if (!infile.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada para RSA: " << input_filename << endl;
        return false;
    }

    ofstream outfile(output_filename, ios::binary);
    if (!outfile.is_open()) {
        cerr << "No se pudo crear el archivo de salida para RSA: " << output_filename << endl;
        infile.close();
        return false;
    }

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    if (!ctx) {
        cerr << "Error creando el contexto EVP_PKEY para RSA." << endl;
        infile.close();
        outfile.close();
        return false;
    }

    if (EVP_PKEY_encrypt_init(ctx) <= 0) {
        cerr << "Error inicializando la encriptación RSA." << endl;
        EVP_PKEY_CTX_free(ctx);
        infile.close();
        outfile.close();
        return false;
    }

    // Establecer padding
    if (EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING) <= 0) { // Asegurar que RSA_PKCS1_OAEP_PADDING esté definido
        cerr << "Error estableciendo el padding RSA." << endl;
        EVP_PKEY_CTX_free(ctx);
        infile.close();
        outfile.close();
        return false;
    }

    // Determinar el tamaño máximo de chunk
    size_t key_size = EVP_PKEY_size(pkey);
    // Para OAEP padding, el max chunk size es key_size - 2*hash_len - 2
    // Asumiendo SHA-1, hash_len = 20
    size_t max_chunk_size = key_size - 2 * 20 - 2;

    vector<unsigned char> in_buffer(max_chunk_size);
    vector<unsigned char> out_buffer(key_size);
    size_t out_len; // Cambiado de int a size_t

    while (infile.good()) {
        infile.read(reinterpret_cast<char*>(in_buffer.data()), max_chunk_size);
        size_t bytes_read = infile.gcount();
        if (bytes_read > 0) {
            if (EVP_PKEY_encrypt(ctx, out_buffer.data(), &out_len, in_buffer.data(), bytes_read) <= 0) { // out_len es size_t
                cerr << "Error encriptando con RSA: " << ERR_error_string(ERR_get_error(), nullptr) << endl;
                EVP_PKEY_CTX_free(ctx);
                infile.close();
                outfile.close();
                return false;
            }
            outfile.write(reinterpret_cast<char*>(out_buffer.data()), out_len);
        }
    }

    EVP_PKEY_CTX_free(ctx);
    infile.close();
    outfile.close();
    return true;
}

int main() {
    // Inicializar OpenSSL
    OPENSSL_init_crypto(0, nullptr);
    ERR_load_crypto_strings();

    // Generar archivos pseudoaleatorios
    cout << "Generando archivos pseudoaleatorios..." << endl;
    for (const auto& size_mb : file_sizes_mb) {
        string filename = "file_" + to_string(size_mb) + "MB.bin";
        if (!generate_random_file(filename, size_mb)) {
            cerr << "Fallo al generar el archivo: " << filename << endl;
            return 1;
        }
        cout << "Archivo generado: " << filename << endl;
    }

    // Generar claves AES y RSA
    unsigned char aes_key[32]; // 256 bits
    unsigned char aes_iv[16];  // AES_BLOCK_SIZE es 16 bytes
    if (RAND_bytes(aes_key, sizeof(aes_key)) != 1 || RAND_bytes(aes_iv, sizeof(aes_iv)) != 1) {
        cerr << "Error generando la clave AES o IV." << endl;
        return 1;
    }

    EVP_PKEY* rsa_pkey = generate_rsa_keypair();
    if (!rsa_pkey) {
        cerr << "Error generando el par de claves RSA." << endl;
        return 1;
    }

    // Abrir archivo CSV para resultados
    ofstream csv_file("resultados_encriptacion.csv");
    if (!csv_file.is_open()) {
        cerr << "No se pudo crear el archivo CSV para los resultados." << endl;
        EVP_PKEY_free(rsa_pkey);
        return 1;
    }

    // Escribir encabezados
    csv_file << "Metodo,Mida_MB,Repeticion,Tiempo_Segundos\n";

    // Iterar sobre métodos y tamaños
    for (const auto& size_mb : file_sizes_mb) {
        string input_filename = "file_" + to_string(size_mb) + "MB.bin";

        // AES-256
        for (int rep = 1; rep <= repetitions; ++rep) {
            string output_filename = "aes_" + to_string(size_mb) + "MB_enc_" + to_string(rep) + ".bin";
            unsigned char iv_copy[16];
            memcpy(iv_copy, aes_iv, 16); // Copiar IV para cada encriptación

            auto start = high_resolution_clock::now();
            if (!encrypt_aes(input_filename, output_filename, aes_key, iv_copy)) {
                cerr << "Error encriptando con AES en tamaño " << size_mb << "MB, repetición " << rep << endl;
                EVP_PKEY_free(rsa_pkey);
                csv_file.close();
                return 1;
            }
            auto end = high_resolution_clock::now();
            duration<double> elapsed = end - start;

            // Escribir resultado al CSV
            csv_file << "AES-256," << size_mb << "," << rep << "," << fixed << setprecision(6) << elapsed.count() << "\n";

            cout << "AES-256: Tamaño " << size_mb << "MB, Repetición " << rep << ", Tiempo: " << elapsed.count() << " segundos." << endl;
        }

        // RSA-256
        for (int rep = 1; rep <= repetitions; ++rep) {
            string output_filename = "rsa_" + to_string(size_mb) + "MB_enc_" + to_string(rep) + ".bin";

            auto start = high_resolution_clock::now();
            if (!encrypt_rsa(input_filename, output_filename, rsa_pkey)) {
                cerr << "Error encriptando con RSA en tamaño " << size_mb << "MB, repetición " << rep << endl;
                EVP_PKEY_free(rsa_pkey);
                csv_file.close();
                return 1;
            }
            auto end = high_resolution_clock::now();
            duration<double> elapsed = end - start;

            // Escribir resultado al CSV
            csv_file << "RSA-256," << size_mb << "," << rep << "," << fixed << setprecision(6) << elapsed.count() << "\n";

            cout << "RSA-256: Tamaño " << size_mb << "MB, Repetición " << rep << ", Tiempo: " << elapsed.count() << " segundos." << endl;
        }
    }

    // Limpieza
    EVP_PKEY_free(rsa_pkey);
    csv_file.close();
    EVP_cleanup();
    CRYPTO_cleanup_all_ex_data();
    ERR_free_strings();

    cout << "Estudio completado. Resultados guardados en 'resultados_encriptacion.csv'." << endl;
    return 0;
}