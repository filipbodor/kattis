#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, g, b, cr, cg, cb, rg, gb;
    scanf("%d %d %d %d %d %d %d %d", &r, &g, &b, &cr, &cg, &cb, &rg, &gb);


    int cnt = 0;

    if (rg - max(0, r - cr) >= 0) {
        rg -= max(0, r - cr);
        cnt += max(0, r - cr);
        if (gb - max(0, b - cb) >= 0) {
            gb -= max(0, b - cb);
            cnt += max(0, b - cb);

            if ((rg + gb) - max(0, g - cg) >= 0) {
                cnt += max(0, g - cg);
                printf("%d\n", cnt);
                return 0;
            }
        }
    }

    printf("-1\n");

    return 0;
}