#include <bits/stdc++.h>
using namespace std;

int AM[11][11];

int bt(int cur, vector<int> &visited, int c, int n) {
    if (c == n) return AM[cur][0];
    visited[cur] = 1;
    int mi = 1e9;
    for (int i = 0; i <= n; i++) if (visited[i] == -1) {
        mi = min(mi, AM[cur][i] + bt(i, visited, c + 1, n));
    }

    visited[cur] = -1;
    return mi;
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c, d, n;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);

        memset(AM, 0, sizeof(AM));
        vector<pair<int, int>> beepers(11);

        beepers[0] = {c, d};

        for (int i = 1; i <= n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);

            beepers[i] = {x, y};
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                AM[i][j] = abs(beepers[i].first - beepers[j].first) + abs(beepers[i].second - beepers[j].second);
            }
        }


        vector<int> visited(n+1, -1);
        int mi = bt(0, visited, 0, n);

        printf("%d\n", mi);

        


    }

    return 0;
}