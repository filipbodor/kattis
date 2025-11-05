#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double ESP = 1e-6;



int main() {
    double r;
    int m, c;
    while (scanf("%lf %d %d", &r, &m, &c) == 3 && !(r == 0 && m == 0 && c == 0)) {
        double actual = PI * r * r;
        double did = (double)((double)c / (double)m) * ((2 * r) * (2 * r));
        printf("%lf %lf\n", actual, did);
    }

    
    return 0;
}