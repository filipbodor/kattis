#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;

struct Point {
    double x, y;
    Point() : x(0), y(0) {} 
    Point(double _x, double _y) : x(_x), y(_y) {} 
};

struct Line {
    double a, b, c;
};

struct Vec {
    double x, y;
    Vec(double _x, double _y) : x(_x), y(_y) {}
};


Vec toVec(const Point &a, const Point &b) {
    return Vec(b.x-a.x, b.y-a.y);
}

Vec scale(const Vec &v, double s) {
    return Vec(v.x*s, v.y*s);
}

double dist(const Point &p1, const Point &p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

void PointTOALine(const Point &p1, const Point &p2, Line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l = {0.0, 0.0, -p1.x};
    } else {
        l = {-(double)(p1.y-p2.y) /(p1.x-p2.x), 1.0, -(double)(l.a*p1.x) - p1.y};
    }
}

double dot(Vec a, Vec b) {
    return (a.x*b.x + a.y*b.y);
}

double norm_sq(Vec v) {
    return v.x*v.x + v.y*v.y;
}

Point translate(const Point &p, const Vec &v) {
    return Point(p.x+v.x, p.y+v.y);
}

double distTOaLine(Point p, Point a, Point b, Point &c) {
    Vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);

    c = translate(a, scale(ab, u));
    return dist(p, c);
}


int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        Point a, b;
        scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);

        Line l;
        PointTOALine(a, b, l);

        int n;
        scanf("%d", &n);
        unordered_map<string, Point> id;
        vector<string> names(n);

        for (int i = 0; i < n; i++) {
            char o[30];
            Point p;
            scanf("%s %lf %lf", &o, &p.x, &p.y);
            names[i] = o;
            id[names[i]] = p;
        }


        vector<double> dists(n);

        double mi = 1e9;
        Point c;

        for (int i = 0; i < n; i++) {
            dists[i] = distTOaLine(id[names[i]], a, b, c);
            mi = min(mi, dists[i]);
            //printf("%lf ", dists[i]);
        }

        for (int i = 0; i < n; i++) {
            if (fabs(dists[i] - mi) < EPS) {
                printf("%s ", names[i].c_str());
            }
        }

        printf("\n");


    }

    return 0;
}