#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <ctime>  // For time measurement
using namespace std;

// Enter number of points: 7
// Enter the coordinates of points (x y):
// 0 3
// 1 1
// 2 2
// 4 4
// 0 0
// 1 2
// 3 1


// A point in 2D plane
struct Point {
    int x, y;
};

// To find the orientation of triplet (p, q, r)
// Returns:
// 0 → collinear
// 1 → clockwise
// 2 → counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;         // collinear
    return (val > 0) ? 1 : 2;       // clock or counterclock wise
}

// Global variable to hold the pivot
Point pivot;

// Compare function for sorting by polar angle
bool compare(Point p1, Point p2) {
    int o = orientation(pivot, p1, p2);
    if (o == 0)
        return (p1.x < p2.x); // Tie-breaker
    return (o == 2); // If counterclockwise, p1 comes before p2
}

// Prints convex hull using Graham Scan
void convexHull(vector<Point>& points) {
    int n = points.size();

    // Step 1: Find the lowest point
    int ymin = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;

        // Pick the lowest or leftmost in case of tie
        if ((y < ymin) || (y == ymin && points[i].x < points[minIndex].x)) {
            ymin = points[i].y;
            minIndex = i;
        }
    }

    // Place the pivot at first position
    swap(points[0], points[minIndex]);
    pivot = points[0];

    // Step 2: Sort the points by polar angle
    sort(points.begin() + 1, points.end(), compare);

    // Step 3: Process points
    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < n; i++) {
        while (hull.size() >= 2) {
            Point top = hull.top(); hull.pop();
            Point nextToTop = hull.top();

            if (orientation(nextToTop, top, points[i]) != 1) {
                hull.push(top); // valid turn
                break;
            }
            // Else it's a right turn — remove top
        }
        hull.push(points[i]);
    }

    // Display the convex hull
    cout << "Points in Convex Hull (in order):\n";
    vector<Point> result;
    while (!hull.empty()) {
        Point p = hull.top();
        result.push_back(p);
        hull.pop();
    }
    reverse(result.begin(), result.end());
    for (Point p : result)
        cout << "(" << p.x << ", " << p.y << ")\n";
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter the coordinates of points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Time measurement using ctime
    clock_t start = clock();

    convexHull(points);

    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << timeTaken * 1000 << " milliseconds\n";

    return 0;
}
