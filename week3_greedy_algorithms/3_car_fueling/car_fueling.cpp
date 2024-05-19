#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int num_refills = 0;
    int current_refill = 0;
    int last_refill = 0;
    stops.insert(stops.begin(), 0); // Insert the start point as the first stop
    stops.push_back(dist); // Insert the destination as the last stop

    while (current_refill <= stops.size()) {
        last_refill = current_refill;

        // Find the furthest reachable stop
        while (current_refill <= stops.size() && stops[current_refill + 1] - stops[last_refill] <= tank) {
            current_refill++;
        }

        // If the furthest reachable stop is the last stop, break the loop
        if (current_refill == stops.size()) {
            break;
        }

        // If the last refill point is the current refill point, then it's not possible to reach the destination
        if (current_refill == last_refill) {
            return -1;
        }

        num_refills++;
    }

    return num_refills;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
