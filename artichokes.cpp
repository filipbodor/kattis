#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, a, b, c, d;
    int n;

    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);

    double cur = -1e9;
    double last = -1e9;
    double ma = 0;

    for (int i = 1; i <= n; i++) {
        double price = (double)p * (sin(a*i+b) + cos(c*i+d) + 2.0);

        if (price > cur) {
            cur = price;
        } else if (cur - price > ma) {
            ma = cur - price;
        }
        last = price;
    }


    printf("%f\n", ma);

    return 0;
}