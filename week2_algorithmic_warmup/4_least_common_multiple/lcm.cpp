#include <iostream>

// Function to calculate the greatest common divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (LCM) using GCD
long long lcm_fast(int a, int b) {
    // LCM * GCD = |a * b|
    long long lcm = (long long) a * b / gcd(a, b);
    return lcm;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << lcm_fast(a, b) << std::endl;
    return 0;
}
