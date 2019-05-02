#include <iostream>
#include <cstdint>
#include <cmath>
#include <limits>

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
    cout << (static_cast<float>(nextafter(1., 2.)) == 1.f ? "one" : "not one") << "\n";
    cout << (static_cast<float>(nextafter(1., 0.)) == 1.f ? "one" : "not one") << "\n";
    cout << (static_cast<float>((nextafterf(1., 2.) - 1.) / 2. + 1.) == 1.f ? "one" : "not one") << "\n";
    cout << (static_cast<float>((nextafterf(1., 2.) - 1.) / 2. + numeric_limits<double>::epsilon() + 1.) == 1.f ? "one" : "not one") << "\n";
}
