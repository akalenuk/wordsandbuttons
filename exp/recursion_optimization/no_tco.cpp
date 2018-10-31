int sum_of_first(int n) {
    if(n == 0)
        return 0;
    auto temp_sum = sum_of_first(n-1);
    return n == 1 ? 1 : (temp_sum + n);
}

int main() {
    return sum_of_first(65536);
}
