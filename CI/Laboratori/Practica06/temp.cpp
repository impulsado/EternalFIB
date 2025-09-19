#include <iostream>
using namespace std;

int main(void) {
    uint32_t usr_mem;

    while (cin >> std::hex >> usr_mem) {
        uint32_t byte = usr_mem&0x1F;
        uint32_t bloque = (usr_mem&0xFFFFFFD0)>>5;
        uint32_t linea = (usr_mem&0xFE0)>>5;
        uint32_t TAG = (usr_mem&0xFFFFF000)>>12;
        cout << std::hex
            << "BYTE: " << byte
            << " Bloque M: " << bloque
            << " linea MC: " << linea
            << " TAG: " << TAG << endl;
    }
}