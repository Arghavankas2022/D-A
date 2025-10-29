//Implementation of Jarvis March 
// The left most point is picked as the starting point, then another random point is picked, for this point we check wether it makes a right turn with any other point , if it does, we discard it and selec the new point,similarily we continue until we reach the initial left most point
// O(n.h), where n is the number of points and h is the number of segments on the hull

#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

// Returns true if q→r→s makes a right turn 
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
           (points[i].x == points[leftmost].x && points[i].y < points[leftmost].y)) { //if there are two left most points, pick one with low y
            leftmost = i;
        }
    }

    vector<Point> hull;
    int q = leftmost, r;

    do {
        hull.push_back(points[q]); //add point to the hull 
        r = (q + 1) % n;

        for (int i = 0; i < n; i++) {
            if (right_turn(points[q], points[r], points[i])) { // if point r makes a right turn with point i --> discard r and mark i as next
                r = i;
            }
        }

        q = r;
    } while (q != leftmost); //stop when the first point is reached

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
