#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::min;
using std::sort;
using std::pair;

struct Point {
    int x, y;
};

double dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double minimal_distance(vector<Point> &points, size_t left, size_t right) {
    if (right - left <= 1) return std::numeric_limits<double>::infinity();
    if (right - left == 2) return dist(points[left], points[left + 1]);
    
    size_t mid = left + (right - left) / 2;
    double d1 = minimal_distance(points, left, mid);
    double d2 = minimal_distance(points, mid, right);
    double d = min(d1, d2);

    vector<Point> strip;
    for (size_t i = left; i < right; ++i) {
        if (abs(points[i].x - points[mid].x) < d) {
            strip.push_back(points[i]);
        }
    }
    
    sort(strip.begin(), strip.end(), [](const Point &a, const Point &b) {
        return a.y < b.y;
    });
    
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; ++j) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    
    return d;
}

double minimal_distance(vector<int> x, vector<int> y) {
    vector<Point> points(x.size());
    for (size_t i = 0; i < x.size(); ++i) {
        points[i] = {x[i], y[i]};
    }

    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.x < b.x;
    });

    return minimal_distance(points, 0, points.size());
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
