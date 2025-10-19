#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi dfs_num, dfs_low, dfs_parent;

int dfsNumberCounter, rootChildren, dfsRoot;
vector<vector<int>> AL;
vector<int> visited;

bool bridge = false;

void findBridge(int u) {
    dfs_num[u] = dfsNumberCounter++;
    dfs_low[u] = dfs_num[u];
    for (int v : AL[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;

            findBridge(v);

            if (dfs_low[v] > dfs_num[u]) {
                bridge = true;
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }

}

int main() {
    int p, c;

    while (scanf("%d %d", &p, &c) && !(p == 0 && c == 0)) {
        AL.assign(p, {});
        dfs_num.assign(p, -1);
        dfs_low.assign(p, 0);
        dfs_parent.assign(p, -1);
        dfsNumberCounter = 0;
        rootChildren = 0;

        int a, b;

        for (int i = 0; i < c; i++) {
            scanf("%d %d", &a, &b);
            AL[a].push_back(b);
            AL[b].push_back(a);
        }

        dfsRoot = 0;
        bridge = false;

        findBridge(0);

        int con = true;
        for (int i = 0; i < p && con; i++) {
            con = dfs_num[i] != -1;
        }

        if (bridge || !con) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        
    }

    return 0;
}