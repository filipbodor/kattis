#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);

        a = a / 100.0 + 1;
        b *= 100.0;
        b = round(b);
        c *= 100.0;
        c = round(c);

        int counter = 0;

        while (b > 0 && counter <= 1205) {
            double temp = b;

            b *= a;
            b = round(b);
            b -= c;


            if (b >= temp) counter += 2000;

            counter++;

            //printf("%llf %llf %llf\n", a, b, c);

        }

        if (counter > 1200) {
            printf("impossible\n");
        } else {
            printf("%d\n", counter);
        }



    }
    

    return 0;
}