#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int ma = 0;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        while (!q.empty() && a - q.front() >= 1000) q.pop();

        q.push(a);

        ma = max(ma, (int)q.size());

    }

    int res = ceil((double)ma / (double)k);

    printf("%d\n", res);

    return 0;
}