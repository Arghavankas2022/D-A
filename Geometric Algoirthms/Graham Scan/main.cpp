// Implementation of the Graham scan algorithm
// sort all points , for the lower hull, start from the first two points, add third point if it doesnt form 
// a right turn, keep adding points with the same logic, if a point is removed it may lead to a right turn in 
// another point, hence that point should be removed too 
// O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Point{
    double x, y;
};

bool right_turn(const Point q, const Point r, const Point s) {
   double d = (s.y - q.y) * (r.x - q.x) - (s.x - q.x) * (r.y - q.y);
    return d < 0; 
}

vector<Point> GrahamScan(vector<Point> &points){
    sort(points.begin(), points.end(), [] (const Point &a, const Point &b){
        if (a.x != b.x) return a.x < b.x;
        else return a.y < b.y;
    });

    vector<Point> hull;
    // add first two points
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    int n = points.size();

    // lower hull
    for (int i = 2; i < n; ++i) {
        while (hull.size() >= 2 && right_turn(hull[hull.size()-2], hull[hull.size()-1], points[i])) { // compare each point with two previous points on the hull
            hull.pop_back(); //remove if it makes a right turn
        }
        hull.push_back(points[i]); // if not, add to the hull
    }

    int h = hull.size();

    // upper hull
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() > h && right_turn(hull[hull.size() - 2], hull[hull.size() - 1], points[i])) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    if (!hull.empty()) hull.pop_back(); // remove duplicate start point

    return hull;
}

int main() {
    
    vector<Point> points = {
        {0, 0},
        {1, 2},
        {2, 1},
        {3, 0},
        {4, 3}
    };

    vector<Point> hull = GrahamScan(points);

    cout << "Convex hull points (anticlockwise order):\n";
    for (auto &p : hull) {
        cout << p.x << " " << p.y << "\n";
    }

    return 0;
}
