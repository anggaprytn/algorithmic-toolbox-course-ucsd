#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int count_frequency(const vector<int>& a, int left, int right, int element) {
    int count = 0;
    for (int i = left; i < right; ++i) {
        if (a[i] == element) {
            ++count;
        }
    }
    return count;
}

int get_majority_element_rec(vector<int>& a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];

    int mid = left + (right - left) / 2;
    int left_majority = get_majority_element_rec(a, left, mid);
    int right_majority = get_majority_element_rec(a, mid, right);

    if (left_majority == right_majority) {
        return left_majority;
    }

    int left_count = count_frequency(a, left, right, left_majority);
    int right_count = count_frequency(a, left, right, right_majority);

    return left_count > (right - left) / 2 ? left_majority : (right_count > (right - left) / 2 ? right_majority : -1);
}

int get_majority_element(vector<int>& a, int left, int right) {
    return get_majority_element_rec(a, left, right);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
