#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char name[35];
        int d1, m1, y1, d2, m2, y2, c;
        scanf("%s %d/%d/%d %d/%d/%d %d", &name, &y1, &m1, &d1, &y2, &m2, &d2, &c);

        if (y1 >= 2010) {
            printf("%s eligible\n", name);
        } else if (y2 >= 1991) {
            printf("%s eligible\n", name);
        } else if (c > 40) {
            printf("%s ineligible\n", name);
        } else {
            printf("%s coach petitions\n", name);
        }
    }

    return 0;
}