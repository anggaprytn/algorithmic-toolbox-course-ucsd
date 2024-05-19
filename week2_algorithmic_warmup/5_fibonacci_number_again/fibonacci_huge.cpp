#include <iostream>

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0, current = 1;

    // Pisano period length for modulo m
    long long period = 0;
    while (true) {
        long long temp = previous;
        previous = current;
        current = (temp + current) % m;
        ++period;

        if (previous == 0 && current == 1)
            break;
    }

    // Reduce n using the Pisano period length to avoid overflow
    n %= period;

    if (n <= 1)
        return n;

    previous = 0;
    current = 1;

    for (long long i = 2; i <= n; ++i) {
        long long temp = previous;
        previous = current;
        current = (temp + current) % m;
    }

    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    return 0;
}
