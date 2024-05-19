#include <iostream>

int get_change(int m) {
    int coins[] = {10, 5, 1}; // Denominations of coins
    int count = 0; // Count of coins used

    for (int i = 0; i < 3; ++i) {
        count += m / coins[i]; // Add the maximum number of coins of denomination coins[i]
        m %= coins[i]; // Update the remaining amount
    }

    return count;
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
    return 0;
}
