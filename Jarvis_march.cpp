#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

// Function to find the leftmost point
int left_most(const vector<Point>& points) {
    int x_min = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].x < points[x_min].x || 
            (points[i].x == points[x_min].x && points[i].y < points[x_min].y)) {  //in case x's are equal, check y's 
            x_min = i;
        }
    }
    return x_min;
}

// Function to find the orientation of the turn
int orientation(const Point& p, const Point& q, const Point& r) {
    int cross_product = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); //cross product

    if (cross_product == 0) {
        return 0; // Collinear 
    } else if (cross_product > 0) {
        return 1; // Counterclockwise
    } else {
        return 2; // Clockwise
    }
}

// Jarvis March 
vector<Point> convex_hull(vector<Point>& points) {
    vector<Point> hull;
    int p = left_most(points); // Start at the leftmost point
    int leftmost = p; // Save the leftmost point to stop the loop when we return to it

    // main Jarvis March loop 
    while (true) {
        // Add the current point to the hull
        hull.push_back(points[p]);

        // Search for the next point that makes the most counterclockwise turn
        int q = p + 1;  // Start with the next point

        // If we're at the last point
        if (q == points.size()) {
            q = 0; // Wrap to the first point
        }

        // Try all points to find the one that makes the most counterclockwise turn
        for (int r = 0; r < points.size(); r++) {
            if (orientation(points[p], points[r], points[q]) == 1) {
                q = r;
            }
        }

        // Set p to the next point for the next iteration
        p = q;

        // Stop if the left most point is reached again (full turn)
        if (p == leftmost) {
            break;
        }
    }

    return hull;
}

// example to try out the algorithm

int main() {
    vector<Point> points = {{1, 0}, {1, 4}, {3, 5}, {2, 3}, {1, 1}};
    
    vector<Point> hull = convex_hull(points);

    cout << "Convex Hull: " << endl;
    for (const auto& coordinate : hull) {
        cout << "(" << coordinate.x << ", " << coordinate.y << ")" << endl;
    }

    return 0;
}
