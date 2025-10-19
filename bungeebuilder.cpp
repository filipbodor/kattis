#include <bits/stdc++.h>
using namespace std;

int inf = 1e9 + 2;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    int l = 0, r = 0, mi = inf;

    int ma = -1;

    for (; r < n; ) {
        if (l == r) {
            r++;
        } else if (h[l] == h[r]) {
            ma = max(ma, h[l] - mi);
            l = r;
            r++;
            mi = inf;
        } else if (h[l] < h[r]) {
            ma = max(ma, h[l] - mi);
            l = r;
            r++;
            mi = inf;
        } else if (h[l] > h[r]) {
            ma = max(ma, h[r] - mi);
            mi = min(mi, h[r]);
            r++;
        }
    }

    if (ma <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", ma);
    }
    return 0;
}