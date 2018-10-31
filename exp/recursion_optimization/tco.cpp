#include <limits>

int sum_of_first(int n) {
    return (n == 1) ? 1 : n + sum_of_first(n-1);
}

int main() {
    return sum_of_first(std::numeric_limits<int>::max());
}
