#include <iostream>

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 2; i <= n; ++i) {
        int tmp = (previous + current) % 10;
        previous = current;
        current = tmp;
    }

    return current;
}

int main() {
    int n;
    std::cin >> n;
    int last_digit = get_fibonacci_last_digit_fast(n);
    std::cout << last_digit << '\n';
    return 0;
}
