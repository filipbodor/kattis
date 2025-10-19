#include <bits/stdc++.h>
using namespace std;

long long dist[300001];
set<long long> tr;

int main() {
    int n;
    scanf("%d", &n);
    

    long long C = 0;
    memset(dist, 0, sizeof(dist));

    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);

    
        tr.insert(a);
        auto curr = tr.find(a);
        long long cost = 0;

        if (i != 0) {
            if (curr != tr.begin()) {
                auto pr = prev(curr);
                cost = max(dist[*(pr)] + 1, cost);
            }
            if (curr != tr.end()) {
                auto ne = next(curr);
                if (ne != tr.end()) {
                    cost = max(dist[*(ne)] + 1, cost);
                }
            }
        }

        dist[a] = cost;
        C += cost;

        printf("%lld\n", C);
    }

    return 0;
}