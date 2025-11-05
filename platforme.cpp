#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if (fabs(y-other.y) > EPS) {
            return y < other.y;
        }
        return x < other.x;
    }
};
struct line {
    double a, b, c;
    line() { a = b = c = 0.0; }
    line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
};

void pointsToLine(const point &a, const point &b, line &l) {
    if (fabs(a.x-b.x) < EPS) {
        l = {1.0, 0.0, -a.x};
    } else {
        l = {-(double)(a.y-b.y) / a.x-b.x, 1.0, -(double)(l.a*a.x) - a.y};
    }
}

bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<point, point>> pts(n);
    vector<line> lines(n, line(0, 0, 0));

    for (int i = 0; i < n; i++) {
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);

        pts[i] = {point(b, a), point(c, a)};
    }

    sort(pts.begin(), pts.end());
    point pr(0.0, 0.0);

    // for (int i = 0; i < n; i++) {
    //     printf("%lf %lf, %lf %lf\n", pts[i].first.x, pts[i].first.y, pts[i].second.x, pts[i].second.y);
    // }

    for (int i = 0; i < n; i++) {
        pointsToLine(pts[i].first, pts[i].second, lines[i]);
    }

    int counter = 0;
    

    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = i - 1; j >= 0 && flag; j--) {
            if (pts[i].first.x + 0.5 >= pts[j].first.x && pts[i].first.x + 0.5 <= pts[j].second.x) {
                counter += pts[i].first.y - pts[j].first.y;
                //printf("%d %d %d\n", i, j, (int)(pts[i].first.y - pts[j].first.y));
                flag = false;
            }
        }
        if (flag) counter += pts[i].first.y;

        flag = true;
        for (int j = i - 1; j >= 0 && flag; j--) {

            if (pts[i].second.x - 0.5 >= pts[j].first.x && pts[i].second.x - 0.5 <= pts[j].second.x) {
                counter += pts[i].first.y - pts[j].first.y;
                //printf("%d %d %d\n", i, j, (int)(pts[i].first.y - pts[j].first.y));
                flag = false;
            }
        }
        if (flag) counter += pts[i].first.y;
    }

    printf("%d\n", counter);



    return 0;
}