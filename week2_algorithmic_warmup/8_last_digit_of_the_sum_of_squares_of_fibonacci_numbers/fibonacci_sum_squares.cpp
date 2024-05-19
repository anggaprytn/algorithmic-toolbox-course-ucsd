#include <iostream>

int fibonacci_sum_squares_fast(long long n) {
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

    // Compute the last digit of the nth and (n + 1)th Fibonacci numbers using iteration
    int current_square = current % 10;
    int next = 1;
    int next_square = next % 10;

    for (int i = 2; i <= n; ++i) {
        int temp = (previous + current) % 10;
        previous = current;
        current = temp;

        current_square = (current_square + (current * current) % 10) % 10;
        temp = (next + current) % 10;
        next = current;
        next_square = (next_square + (temp * temp) % 10) % 10;
    }

    // Compute the sum of squares of Fibonacci numbers up to the nth Fibonacci number
    int sum_squares = (current_square * next_square) % 10;
    return sum_squares;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
    return 0;
}
