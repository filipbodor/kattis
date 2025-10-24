#include <bits/stdc++.h>
using namespace std;

int n, t;

int main() {
    scanf("%d %d", &n, &t);

    vector<pair<pair<double, double>, int>> points(n);

    double real = 0.0;

    for (int i = 0; i < n; i++) {
        double a, b;
        int c;
        scanf("%lf %lf %d", &a, &b, &c);

        points[i] = {{a, b}, c};

        if (i != 0) real += hypot(points[i].first.first - points[i-1].first.first, points[i].first.second - points[i-1].first.second);
    }

    double gps = 0.0;
    int curt = 0;
    int cur2 = 0;
    pair<double, double> curpos = points[0].first;
    int ft = points[points.size() - 1].second;

    while (curt <= ft) {
        
        while (cur2 + 1 < n && points[cur2+1].second <= curt) {
            cur2++;
        }

        double cu = points[cur2+1].second - points[cur2].second;
        double ccc = curt - points[cur2].second;

        double css = ccc / cu;

        pair<double, double> newPos = {points[cur2].first.first + (points[cur2+1].first.first - points[cur2].first.first) * css, points[cur2].first.second + (points[cur2+1].first.second - points[cur2].first.second) * css};

        gps += hypot(newPos.first - curpos.first, newPos.second - curpos.second);

        curpos = newPos;
        curt += t;
    }
    gps += hypot(points[points.size() - 1].first.first - curpos.first, points[points.size() - 1].first.second - curpos.second);



    printf("%lf\n", (1 - gps / real) * 100);

    return 0;
}