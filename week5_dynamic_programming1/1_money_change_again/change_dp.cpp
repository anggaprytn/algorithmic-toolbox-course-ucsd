#include <iostream>
#include <vector>
#include <algorithm>

int get_change(int m) {
    std::vector<int> coins = {1, 3, 4};
    std::vector<int> min_coins(m + 1, m + 1);
    min_coins[0] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int coin : coins) {
            if (i >= coin) {
                min_coins[i] = std::min(min_coins[i], min_coins[i - coin] + 1);
            }
        }
    }

    return min_coins[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
