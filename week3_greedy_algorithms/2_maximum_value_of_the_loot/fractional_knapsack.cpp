#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// Structure to represent an item with its value and weight
struct Item {
    int value;
    int weight;
    double value_per_weight; // Value per unit weight for sorting
};

// Function to compare items based on value per unit weight in descending order
bool compare(Item a, Item b) {
    return a.value_per_weight > b.value_per_weight;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    // Create a vector of items
    vector<Item> items(weights.size());
    for (size_t i = 0; i < items.size(); ++i) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].value_per_weight = static_cast<double>(values[i]) / weights[i];
    }

    // Sort items based on value per unit weight in descending order
    sort(items.begin(), items.end(), compare);

    // Fill the knapsack greedily
    for (size_t i = 0; i < items.size(); ++i) {
        if (capacity == 0)
            return value;

        int a = std::min(capacity, items[i].weight);
        value += a * items[i].value_per_weight;
        capacity -= a;
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
