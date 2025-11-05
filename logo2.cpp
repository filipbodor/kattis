#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-6;

double DEG_to_RAD(double d) { return d*M_PI / 180.0; };
double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double x, double y) : x(x), y(y) {}
};

struct vec {
    double x, y;
    vec(double x, double y) : x(x), y(y) {}
};

vec toVec(const point &a, const point &b) {
    return vec(b.x-a.x, b.y-a.y);
}

double dot(vec a, vec b) {
    return (a.x*b.x + a.y*b.y);
}

double norm_sq(vec v) {
    return v.x*v.x + v.y*v.y;
}

double angle(const point &a, const point &b, const point &o) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return RAD_to_DEG(acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))));

}

double dist(const point &a, const point &b) {
    return hypot(a.x-b.x, a.y-b.y);
}

void rotate(point &p, double theta) {
    double rad = DEG_to_RAD(theta);
    p = point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}

double cross(vec a, vec b) {
    return a.x*b.y - a.y*b.x;
}

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > EPS;
}

int main() {
    int T;
    scanf(" %d", &T);

    while (T--) {
        int n;
        scanf(" %d", &n);

        point st(0.0, 0.0);
        point unitVec = point(0.0, 1.0);

        string fu = "";
        point fup(0.0, 0.0);

        for (int i = 0; i < n; i++) {
            char f[5];
            scanf(" %s ", &f);
            string fg = f;
            char c;
            scanf(" %c", &c);


            if (c == '?') {
                fup = st;
                fu = f;
            } else {
                int num = c - '0';
                while (scanf("%c", &c) == 1 && c >= '0' && c <= '9') {
                    num = num * 10 + c - '0';
                }
                
                if (fg == "fd") {
                    st.x += unitVec.x * (double)num;
                    st.y += unitVec.y * (double)num;
                } else if (fg == "bk") {
                    st.x -= unitVec.x * (double)num;
                    st.y -= unitVec.y * (double)num;
                } else if (fg == "rt") {
                    rotate(unitVec, (double)num);
                } else if (fg == "lt") {
                    rotate(unitVec, -(double)num);
                }
            }
        }
        point zero(0.0, 0.0);

        //printf("%lf %lf, %lf %lf, %lf\n", st.x, st.y, fup.x, fup.y, angle(zero, st, fup));

        int res; 
        if (fu == "fd" || fu == "bk") {
            res = round(dist(zero, st));
        } else {
            res = round(angle(st, zero, fup));

            if ((fu == "rt" && ccw(st, fup, zero)) || (!ccw(st, fup, zero) && fu == "lt")) {
                res = 360 - res;
            }

        }

        printf("%d\n", res);




    }

    return 0;
}