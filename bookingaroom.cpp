#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, n;

    scanf("%d %d", &r, &n);

    int d[r + 1];
    for (int i = 0; i <= r; i++) d[i] = 0;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        d[a] = 1;
    }

    if (r == n) {
        printf("too late\n");
    } else {
        for (int i = 1; i <= r; i++) {
            if (d[i] == 0) {
                printf("%d\n", i);
                break;
            }

        }
    }

    return 0;
}