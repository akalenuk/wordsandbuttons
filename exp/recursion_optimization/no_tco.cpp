#include <limits>

int sum_of_first(int n) {
    auto temp_sum = sum_of_first(n-1);
    return n == 1 ? 1 : temp_sum + n;
}

int main() {
    return sum_of_first(std::numeric_limits<int>::max());
}
