#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Point {
    double x, y;
};

bool compareX(Point &a, Point &b) {
    return a.x < b.x;
}

bool compareY(Point& a, Point& b) {
    return a.y < b.y;
}

double getDistance(Point &p1, Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); 
}

double BruteForce(vector<Point> &res, int left, int right) {
    double min_dist = 1e18;
    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            min_dist = min(min_dist, getDistance(res[i], res[j]));
        }
    }
    return min_dist;
}

// Utility function to find the closest points strictly within the middle strip
double stripClosest(vector<Point>& strip, double d) {
    double minDist = d;

    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); ++i) {
        // Stop the loop early if the Y distance exceeds our current minDist.
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, getDistance(strip[i], strip[j]));
        }
    }
    
    return minDist; 
}

double closest(vector<Point> &listRes, int left, int right) {
    // Base case: <= 3 -> Brute force
    if(right - left <= 2) {
        return BruteForce(listRes, left, right);
    }

    // Find the middle point
    int mid = (right + left) / 2;
    Point midPoint = listRes[mid];

    double dl = closest(listRes, left, mid);
    double dr = closest(listRes, mid + 1, right);

    double d = min(dl, dr);

    vector<Point> tmp;
    for (int i = left; i <= right; ++i) {
        if(abs(listRes[i].x - midPoint.x) < d) {
            tmp.push_back(listRes[i]);
        }
    }

    return min(d, stripClosest(tmp, d));
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test; 
    while(test--) {
        int n; cin >> n;
        vector<Point> listRes(n);

        for (int i = 0; i < n; ++i) cin >> listRes[i].x >> listRes[i].y;
        sort(listRes.begin(), listRes.end(), compareX);

        double ans = closest(listRes, 0, n - 1);
        cout << fixed << setprecision(6) << ans << endl;
    }

    return 0;
}