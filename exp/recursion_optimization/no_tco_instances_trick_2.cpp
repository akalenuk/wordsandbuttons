template <int instance_no, int divisor>
int sum_of_first(int n) {
    if(n == 0)
        return 0;
    auto temp_sum = sum_of_first<(instance_no + 1) % divisor, divisor>(n-1);
    return n == 1 ? 1 : temp_sum + n;
}

int main() {
    return sum_of_first<0, 2>(65536);
}
