#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);

    double left = y;
    double devider = 0.0;

    for (int i = 0; i < n; i++) {
        int a, b;
        double c;
        scanf("%d %d %lf", &a, &b, &c);

        devider += ((double)b - (double)a) * c;
        left -= (b - a);
    }

    devider += left;

    double res = (double)x / devider;
    printf("%lf\n", res);


    return 0;
}