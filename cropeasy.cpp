#include <bits/stdc++.h>
using namespace std;


int main() {
    int idx = 0, T;
    scanf("%d", &T);

    while (T--) {
        idx++;
        long long n, A, B, C, D, x1, x2, M;
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n, &A, &B, &C, &D, &x1, &x2, &M);

        vector<pair<long long, long long>> pts(n);

        set<pair<long long, long long>> isi;

        pts[0] = {x1, x2};
        for (int i = 1; i < n; i++) {
            x1 = (A * x1 + B) % M;
            x2 = (C * x2 + D) % M;
            pts[i] = {x1, x2};
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if ((pts[i].second + pts[j].second + pts[k].second) % 3 == 0 && (pts[i].first + pts[j].first + pts[k].first) % 3 == 0) {
                        cnt++;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", idx, cnt);
    }

    return 0;
}