#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

void min_and_max(int i, int j, const vector<vector<long long>> &min_values, const vector<vector<long long>> &max_values, const string &ops, long long &min_val, long long &max_val) {
    min_val = LLONG_MAX;
    max_val = LLONG_MIN;
    for (int k = i; k < j; ++k) {
        long long a = eval(max_values[i][k], max_values[k + 1][j], ops[k]);
        long long b = eval(max_values[i][k], min_values[k + 1][j], ops[k]);
        long long c = eval(min_values[i][k], max_values[k + 1][j], ops[k]);
        long long d = eval(min_values[i][k], min_values[k + 1][j], ops[k]);
        min_val = min(min_val, min(a, min(b, min(c, d))));
        max_val = max(max_val, max(a, max(b, max(c, d))));
    }
}

long long get_maximum_value(const string &exp) {
    int n = exp.size() / 2 + 1;
    vector<vector<long long>> min_values(n, vector<long long>(n, 0));
    vector<vector<long long>> max_values(n, vector<long long>(n, 0));
    vector<long long> nums(n);
    vector<char> ops(n - 1);

    for (int i = 0; i < n; ++i) {
        nums[i] = exp[2 * i] - '0';
    }
    for (int i = 0; i < n - 1; ++i) {
        ops[i] = exp[2 * i + 1];
    }

    for (int i = 0; i < n; ++i) {
        min_values[i][0] = nums[i];
        max_values[i][0] = nums[i];
    }

    for (int s = 1; s < n; ++s) {
        for (int i = 0; i < n - s; ++i) {
            int j = i + s;
            long long min_val, max_val;
            min_and_max(i, j, min_values, max_values, ops, min_val, max_val);
            min_values[i][j] = min_val;
            max_values[i][j] = max_val;
        }
    }

    return max_values[0][n - 1];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
