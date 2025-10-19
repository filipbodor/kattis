#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        long long c = 0;
        scanf("%d", &n);

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 0; i < n; i++) {
            int l;
            scanf("%d", &l);
            pq.push(l);
        }

        long long counter = 0;

        while (pq.size() >= 2) {
            long long c = pq.top(); pq.pop();
            c += pq.top(); pq.pop();
            counter += c;
            pq.push(c);
        }

        printf("%ld\n", counter);
    }

    return 0;
}