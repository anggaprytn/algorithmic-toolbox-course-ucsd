#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

// Custom comparator function to compare strings in a specific order
bool compareStrings(const string &a, const string &b) {
    string ab = a + b; // Concatenate strings a and b
    string ba = b + a; // Concatenate strings b and a
    return ab > ba;    // Compare which concatenation forms a larger number
}

string largest_number(vector<string> a) {
    // Sort strings using the custom comparator function
    std::sort(a.begin(), a.end(), compareStrings);

    // Concatenate sorted strings to form the largest number
    string result;
    for (const auto &s : a) {
        result += s;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
    return 0;
}
