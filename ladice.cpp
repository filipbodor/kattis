#include <bits/stdc++.h>
using namespace std;

vector<int> dr;
vector<pair<int, int>> itms;

class UnionFind {
private:
    int n;
    vector<int> rank, p, sz;

public:
    UnionFind(int inN) : n(inN) {
        rank.assign(n+1, 0);
        p.assign(n+1, 1); for (int i = 0; i <= n; i++) p[i]= i;
        sz.assign(n+1, 1);
    }

    int find(int u) {
        if (p[u] == u) return u;
        return p[u] = find(p[u]);
    }

    bool getSize(int u) {
        if (sz[find(u)] == 0) return false;
        sz[find(u)]--;
        return true;
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (rank[pa] == rank[pb]) {
            rank[pa]++;
            p[pb] = pa;
            sz[pa] += sz[pb];
        } else if (rank[pa] > rank[pb]) {
            p[pb] = pa;
            sz[pa] += sz[pb];
        } else {
            p[pa] = pb;
            sz[pb] += sz[pa];
        }
    }
};

int main() {
    int n, l;
    scanf("%d %d", &n, &l);

    dr.assign(l, -1);
    itms.assign(n, {});

    UnionFind un(l);
    

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        itms[i] = {a, b};
        un.unite(a, b);

        if (un.getSize(a)) {
            printf("LADICA\n");
        } else {
            printf("SMECE\n");
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     if (un.getSize(itms[i].first)) {
    //         printf("LADICA\n");
    //     } else {
    //         printf("SMECE\n");
    //     }
    // }

    return 0;
}