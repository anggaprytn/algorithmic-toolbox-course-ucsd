#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int current = 1; // Start with the first integer

    while (n > 0) {
        // If the current number is less than or equal to the remaining sum, add it to summands
        if (current <= n) {
            summands.push_back(current);
            n -= current;
            current++; // Move to the next integer
        } else {
            // If the current number is greater than the remaining sum, add the remaining sum to summands
            summands.push_back(n);
            n = 0;
        }
    }

    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
    return 0;
}
