#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

// Returns true if q→r→s makes a right turn (clockwise)
bool right_turn(const Point &q, const Point &r, const Point &s) {
    double d = (s.y - q.y) * (r.x - q.x) - (s.x - q.x) * (r.y - q.y);
    return d < 0;
}

vector<Point> ConvexHull(vector<Point> &points) {
    int n = points.size();
    if (n < 3) return {}; // convex hull not possible

    // Find the leftmost point (if tie, lowest y)
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x ||
           (points[i].x == points[leftmost].x && points[i].y < points[leftmost].y)) {
            leftmost = i;
        }
    }

    vector<Point> hull;
    int q = leftmost, r;

    do {
        hull.push_back(points[q]);
        r = (q + 1) % n;

        for (int i = 0; i < n; i++) {
            if (right_turn(points[q], points[r], points[i])) {
                r = i;
            }
        }

        q = r;
    } while (q != leftmost);

    return hull;
}

int main() {
    vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1}, {2, 1},
        {3, 0}, {0, 0}, {3, 3}
    };

    vector<Point> hull = ConvexHull(points);

    cout << "Convex Hull points:\n";
    for (auto &p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";

    return 0;
}
