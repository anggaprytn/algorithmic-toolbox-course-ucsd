#include <iostream>

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    // Initialize Fibonacci sequence with 0 and 1
    int previous = 0, current = 1;

    // Pisano period length for modulo 10
    int period = 60; // Pisano period for modulo 10 is 60

    // Reduce n using the Pisano period length to avoid overflow
    n %= period;

    if (n <= 1)
        return n;

    // Compute the last digit of the nth Fibonacci number using iteration
    for (int i = 2; i <= n; ++i) {
        int temp = (previous + current) % 10;
        previous = current;
        current = temp;
    }

    // Compute the sum of Fibonacci numbers up to the nth Fibonacci number
    int sum = (current == 0) ? 9 : current - 1; // Handling special case when current is 0
    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
    return 0;
}
