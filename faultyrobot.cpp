#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ALf;
vector<vector<int>> AL;
vector<vector<int>> vis;


void dp(int u, int buggy, vector<int> &res) {
    bool flag = true;

    vis[u][buggy] = 1;

    if (!buggy) {
        for (int i : AL[u]) if (vis[i][1] == -1) {
            dp(i, true, res);
        }
    }   

    for (int i : ALf[u]) if (vis[i][buggy] == -1) {
        dp(i, buggy, res);
    }


    if (ALf[u].empty()) res[u] = 1;
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    AL.assign(n + 1, {});
    ALf.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a < 0) ALf[-a].push_back(b);
        else AL[a].push_back(b);
    }


    vis.assign(n + 1, {-1, -1});

    vector<int> res(n + 1, 0);
    
    dp(1, false, res);

    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += res[i];

    printf("%d\n", cnt);

    return 0;
}