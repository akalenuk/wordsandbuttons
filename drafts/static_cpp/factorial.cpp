#include <iostream>

template <int N>
int factorial(){
    return N == 1 
        ? 1
        : N*factorial<N - 1 + (N == 1)>();
}

int main(){
    return factorial<3>();
}

