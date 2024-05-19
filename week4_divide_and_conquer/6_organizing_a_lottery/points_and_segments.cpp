#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    vector<pair<int, char>> events;

    for (size_t i = 0; i < starts.size(); ++i) {
        events.emplace_back(starts[i], 'l'); // 'l' indicates the start of a segment
        events.emplace_back(ends[i], 'r');   // 'r' indicates the end of a segment
    }

    for (size_t i = 0; i < points.size(); ++i) {
        events.emplace_back(points[i], 'p'); // 'p' indicates a point
    }

    std::sort(events.begin(), events.end());
    
    int segment_count = 0;
    std::unordered_map<int, int> point_counts;

    for (const auto &event : events) {
        if (event.second == 'l') {
            segment_count++;
        } else if (event.second == 'r') {
            segment_count--;
        } else {
            point_counts[event.first] = segment_count;
        }
    }

    for (size_t i = 0; i < points.size(); ++i) {
        cnt[i] = point_counts[points[i]];
    }

    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        std::cin >> starts[i] >> ends[i];
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        std::cin >> points[i];
    }
    // Use fast_count_segments
    vector<int> cnt = fast_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        std::cout << cnt[i] << ' ';
    }
}
