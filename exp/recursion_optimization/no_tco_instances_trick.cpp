#include <limits>

template <int instance_no, int divisor>
int sum_of_first(int n) {
    auto temp_sum = sum_of_first<(instance_no + 1) % divisor, divisor>(n-1);
    return n == 1 ? 1 : temp_sum + n;
}

int main() {
    return sum_of_first<0, 4>(std::numeric_limits<int>::max());
}
