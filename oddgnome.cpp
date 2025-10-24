#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);

        int last;
        scanf("%d", &last);

        for (int j = 1; j < m; j++) {
            int a;
            scanf("%d", &a);


            if (last == -2) continue;

            if (a != (last + 1)) {
                printf("%d\n", j+1);
                last = -2;
            } else {
                last = a;
            }
        }
    }

    return 0;
}