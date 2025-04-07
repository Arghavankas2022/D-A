#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

int find_lowest(const vector<Point>& points) {
    int y_min = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].y < points[y_min].y || 
            (points[i].y == points[y_min].y && points[i].x < points[y_min].x)) {
            y_min = i;
        }
    }
    return y_min;
}

int orientation(const Point& p, const Point& q, const Point& r) {
    int cross_product = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (cross_product == 0) return 0; // collinear
    return (cross_product > 0) ? 1 : 2; // 1 = counterclockwise, 2 = clockwise
}

Point lowest_point;

bool compare(const Point& p, const Point& q) {
    int o = orientation(lowest_point, p, q);
    if (o == 0) {
        int distA = (lowest_point.x - p.x) * (lowest_point.x - p.x) +
                    (lowest_point.y - p.y) * (lowest_point.y - p.y);
        int distB = (lowest_point.x - q.x) * (lowest_point.x - q.x) +
                    (lowest_point.y - q.y) * (lowest_point.y - q.y);
        return distA < distB;
    }
    return o == 1; // true if counterclockwise
}

vector<Point> graham_scan(vector<Point>& points) {
    if (points.size() < 3) return {};

    int min_index = find_lowest(points);
    swap(points[0], points[min_index]);
    lowest_point = points[0];

    sort(points.begin() + 1, points.end(), compare);

    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    for (int i = 3; i < points.size(); i++) {
        while (hull.size() >= 2 &&
               orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 1) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    vector<Point> points = {
        {1, 3}, {3, 10}, {1, 1}, {2, 1},
        {3, 10}, {1, 0}, {3, 3}
    };

    vector<Point> hull = graham_scan(points);

    cout << "Convex Hull:\n";
    for (const auto& pt : hull) {
        cout << "(" << pt.x << ", " << pt.y << ")\n";
    }

    return 0;
}

