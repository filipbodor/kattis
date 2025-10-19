#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int l, n;
        scanf("%d %d", &l, &n);

        int mi = -1, ma = -1;

        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);

            mi = max(mi, min(a, l - a));
            ma = max({ma, a, l - a});
        }
        printf("%d %d\n", mi, ma);
    }

    return 0;
}