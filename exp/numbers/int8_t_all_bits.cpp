#include <iostream>
#include <cstdint>

using namespace std;

void print_8_bits(int8_t a) {
    cout << ((a & 0x80) ? 1 : 0);    
    cout << ((a & 0x40) ? 1 : 0);    
    cout << ((a & 0x20) ? 1 : 0);    
    cout << ((a & 0x10) ? 1 : 0);    
    cout << ((a & 0x08) ? 1 : 0);    
    cout << ((a & 0x04) ? 1 : 0);    
    cout << ((a & 0x02) ? 1 : 0);    
    cout << ((a & 0x01) ? 1 : 0);    
}

int main() {
    int8_t a = -128;
    for(auto i = 0u; i < 256; ++i) {
        print_8_bits(a++);
        cout << "\n";
    } 
}
