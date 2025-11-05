#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    point() { x = y = 0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

const double PI = acos(-1.0);

double DEG_to_RAD(double d) { return d*PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

void rotate(point &p, double theta) {
    double rad = DEG_to_RAD(theta);
    p = point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}

double dist(const point &a, const point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    while (true) {
        string a;
        getline(cin, a);
        int n = stoi(a);

        if (n == 0) break;

        vector<point> pts(n);

        for (int j = 0; j < n; j++) {
            getline(cin, a);

            double x = -10000, y = -10000;

            vector<pair<string, double>> inst;
            string in = "";
            string temp = "";

            for (int i = 0; i < a.size(); i++) {
                if (a[i] == ' ' || a[i] == '\n') {
                    if (x == -10000) x = stod(temp);
                    else if (y == -10000) y = stod(temp);
                    else if (in == "") in = temp;
                    else {
                        inst.push_back({in, stod(temp)});
                        in = "";
                    }
                    temp = "";
                } else {
                    temp += a[i];
                }
            }
            if (temp != "") {
                inst.push_back({in, stod(temp)});
            }

            point cur(x, y);
            point unitVec(1.0, 0.0);

            for (int i = 0; i < (int)inst.size(); i++) {
                if (inst[i].first[0] == 's' || inst[i].first[0] == 't') {
                    rotate(unitVec, inst[i].second);
                } else {
                    cur.x += unitVec.x * inst[i].second;
                    cur.y += unitVec.y * inst[i].second;
                }
            }

            pts[j] = cur;
        }


        double suX = 0.0, suY = 0.0;
        for (int i = 0; i < n; i++) {
            suX += pts[i].x;
            suY += pts[i].y;
        }


        double avgX = suX / (double)n, avgY = suY / (double)n;
        point avgP(avgX, avgY);

        double ma = -1.0;
        for (int i = 0; i < n; i++) {
            ma = max(ma, dist(avgP, pts[i]));
        }

        printf("%lf %lf %lf\n", avgX, avgY, ma);



    }

    return 0;
}