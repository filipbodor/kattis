#include <bits/stdc++.h>
using namespace std;

int main() {

    int rs = 0, ys = 0;

    for (int i = 0; i < 10; i++) {

        vector<double> red {};
        vector<double> yel {};

        int n = 0;
        scanf("%d", &n);
        red.assign(n, 0);

        for (int j = 0; j < n; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            red[j] = hypot(a - 144, b - 84);
        }

        int m = 0;
        scanf("%d", &m);
        yel.assign(m, 0);

        for (int j = 0; j < m; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            yel[j] = hypot(a - 144, b - 84);
        }

        sort(red.begin(), red.end());
        sort(yel.begin(), yel.end());

        if ((yel.size() == 0 && !red.size() == 0) || red[0] < yel[0]) {

            for (int j = 0; j < n; j++) {
                bool flag = true;
                for (int k = 0; k < m && flag; k++) {
                    if (red[j] > yel[k]) flag = false;
                }
                if (flag) rs++;
            }
        } else {
            for (int j = 0; j < m; j++) {
                bool flag = true;
                for (int k = 0; k < n && flag; k++) {
                    if (yel[j] > red[k]) flag = false;
                }
                if (flag) ys++;
            }
        }
    }

    printf("%d %d\n", rs, ys);

    return 0;
}