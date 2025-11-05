#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        double r, n, d, m, s;
        scanf("%lf %lf %lf %lf %lf", &r, &n, &d, &m, &s);

        double deg = d + m / 60.0 + (s / 3600.0);


        set<double> we;
        we.insert(360.0);

        int dd = 1, mm = 1, ss = 1;
        if (d != 0) dd = lcm(360, (int)d) / (int)d;
        if (m != 0) mm = lcm(360*60, (int)m) / (int)m;
        if (s != 0) ss = lcm(360*360, (int)s) / (int)s;
        

        int lc = lcm(lcm(dd, mm), ss);

        //printf("lc %d\n", lc);
        double c = 0.0;

        for (int i = 0; i < n && i <= lc; i++) {
            we.insert(c);
            c += deg;
            if (c >= 360.0) c -= 360.0; 
        }

        auto last = we.begin();

        double ma = 0.0;

        
        for (auto it = we.begin(); it != we.end(); it++) {
            ma = max(ma, *it - *last);

            //printf("%lf %lf\n", *it, *last);
            last = it;
        }


        double ans = PI * r * r * (ma / 360.0);
        printf("%lf\n", ans);
    }

    return 0;
}