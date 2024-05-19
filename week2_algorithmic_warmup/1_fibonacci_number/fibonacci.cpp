#include <iostream>
#include <cassert>

// Efficient Fibonacci algorithm using iteration
int fibonacci_fast(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = b;
        b += a;
        a = temp;
    }

    return b;
}

// Naive recursive Fibonacci algorithm
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

// Test function to compare the fast and naive Fibonacci algorithms
void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_fast(n) << '\n';

    // Uncomment the following line to test the solution
    // test_solution();

    return 0;
}
