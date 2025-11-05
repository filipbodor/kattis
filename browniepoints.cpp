#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};


int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        vector<Point> ps(n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &ps[i].x, &ps[i].y);
        }


        Point center = ps[n/2];

        int cntO = 0, cntS = 0;

        for (int i = 0; i < n; i++) {
            if ((ps[i].x < center.x && ps[i].y > center.y) || (ps[i].x > center.x && ps[i].y < center.y)) {
                cntO++;
            } else if ((ps[i].x > center.x && ps[i].y > center.y) || (ps[i].x < center.x && ps[i].y < center.y)) {
                cntS++;
            }
        }

        printf("%d %d\n", cntS, cntO);

    }

    return 0;
}