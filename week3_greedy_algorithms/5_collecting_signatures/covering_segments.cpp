#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
};

// Custom comparator function to sort segments by their end points
bool compareSegments(const Segment &a, const Segment &b) {
    return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;

    // Sort segments by their end points
    std::sort(segments.begin(), segments.end(), compareSegments);

    int point = segments[0].end; // Start with the end point of the first segment
    points.push_back(point);

    // Iterate through segments and collect points
    for (size_t i = 1; i < segments.size(); ++i) {
        // If the current segment does not cover the current point,
        // add the end point of the current segment to the points to collect
        if (point < segments[i].start || point > segments[i].end) {
            point = segments[i].end;
            points.push_back(point);
        }
    }

    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
    return 0;
}
