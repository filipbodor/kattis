#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double pointDist(const Point &a, const Point &b) {
    return hypot(a.x - b.x, a.y- b.y);
}



int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        Point p; 
        scanf("%lf %lf", &p.x, &p.y);

        int n;
        scanf("%d", &n);

        vector<Point> ps(n);

        for (int i = 0; i < n; i++ ){
            scanf("%lf %lf", &ps[i].x, &ps[i].y);
        }

        bool flag = true;
        for (int i = 0; i < n && flag; i++) {
            if (pointDist(p, ps[i]) <= 8.0) {
                flag = false;
            }
        }

        if (!flag) printf("light a candle\n");
        else printf("curse the darkness\n");

    }

    return 0;
}