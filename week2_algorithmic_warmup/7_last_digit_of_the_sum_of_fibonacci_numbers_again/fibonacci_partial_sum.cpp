#include <iostream>

int fibonacci_partial_sum_fast(long long from, long long to) {
    if (to <= 1)
        return to;

    // Pisano period length for modulo 10
    int period = 60; // Pisano period for modulo 10 is 60

    // Reduce from and to using the Pisano period length to avoid overflow
    from %= period;
    to %= period;

    int current = 0, next = 1;

    // Find the last digit of the sum of Fibonacci numbers up to the 'to' index
    int sum_to = 0;
    for (int i = 0; i <= to; ++i) {
        if (i >= from)
            sum_to = (sum_to + current) % 10;

        int temp = (current + next) % 10;
        current = next;
        next = temp;
    }

    // Find the last digit of the sum of Fibonacci numbers up to the 'from - 1' index
    int sum_from = 0;
    for (int i = 0; i < from; ++i) {
        int temp = (current + next) % 10;
        current = next;
        next = temp;
    }

    // Compute the partial sum of Fibonacci numbers from 'from' to 'to'
    int partial_sum = (sum_to - sum_from + 10) % 10; // Ensure the result is positive
    return partial_sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_partial_sum_fast(from, to) << '\n';
    return 0;
}
