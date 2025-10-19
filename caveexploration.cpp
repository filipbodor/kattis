#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AL;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

int articulationPointAndBridge(int u) {
    dfs_num[u] = dfsNumberCounter++;
    dfs_low[u] = dfs_num[u];
    int counter = 0;
    for (auto v : AL[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == dfsRoot) ++rootChildren;

            int a = 1 + articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u]) {
                articulation_vertex[u] = 1;
                if (dfs_low[v] != dfs_num[u]) {
                    counter -= a;
                }
            } if (dfs_low[v] > dfs_num[u]) {
                // bridge
            } else if (u == dfsRoot && dfs_num[u] == dfs_low[v]) {
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            counter += a;
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }
    return counter;
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    AL.assign(n, {});

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        AL[a].emplace_back(b);
        AL[b].emplace_back(a); 

    }   

    dfs_num.assign(n, -1);
    dfs_low.assign(n, 0);
    dfs_parent.assign(n, -1);
    articulation_vertex.assign(n, 0);
    dfsNumberCounter = 0;
    dfsRoot = 0;
    rootChildren = 0;
    int res = 1 + articulationPointAndBridge(0);

    printf("%d\n", res);

    




    return 0;
}