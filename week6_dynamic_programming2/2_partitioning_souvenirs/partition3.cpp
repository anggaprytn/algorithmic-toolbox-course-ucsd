#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;

bool can_partition_into_three(vector<int> &A, int sum) {
    int n = A.size();
    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(sum + 1, vector<bool>(sum + 1, false)));

    dp[0][0][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            for (int k = 0; k <= sum; ++k) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= A[i - 1]) {
                    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j - A[i - 1]][k];
                }
                if (k >= A[i - 1]) {
                    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k - A[i - 1]];
                }
            }
        }
    }

    return dp[n][sum][sum];
}

int partition3(vector<int> &A) {
    int total_sum = 0;
    for (int value : A) {
        total_sum += value;
    }

    if (total_sum % 3 != 0) {
        return 0;
    }

    int partition_sum = total_sum / 3;

    if (can_partition_into_three(A, partition_sum)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}
