#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

int optimal_weight(int W, const vector<int> &w) {
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (w[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + w[i - 1]);
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
