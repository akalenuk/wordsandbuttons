#include <iostream>
#include <cstdint>

using namespace std;

void print_32_bits(float x) {
    const uint32_t a = *(reinterpret_cast<const uint32_t*>(&x));
    uint32_t mask = 0x80'00'00'00;
    for(auto i = 0u; i < 32; ++i) {
        cout << ((a & mask) ? 1 : 0);
        mask >>= 1;
    }
    cout << "\n";
}

int main() {
    print_32_bits(0.5f);
    print_32_bits(1.0f);
    print_32_bits(2.0f);
}
