#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<int> visited;

int dfs(int u) {
    visited[u] = 1;

    int counter = 1;

    for (int v : AL[u]) if (visited[v] == -1) {
        counter += dfs(v);
    }
    return counter;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m, l;
        scanf("%d %d %d", &n, &m, &l);

        AL.assign(n+1, {});
        visited.assign(n+1, -1);

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            AL[a].push_back(b);
        }

        vector<int> start(l);

        for (int i = 0; i < l; i++) {
            scanf("%d", &start[i]);
        }   

        int res = 0;

        for (int i : start) if (visited[i] == -1) {
            res += dfs(i);
        }

        printf("%d\n", res);


    }


    return 0;
}