#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {
private: 
    vi rank;
    vi p;
public: 
    UnionFind(int n) {
        rank.assign(n, 1);
        p.assign(n, 0); for (int i = 0; i < n; i++) p[i] = i;
    }

    int find(int a) {
        if (p[a] == a) return a;
        return p[a] = find(p[a]);
    }

    bool isSameSet(int a, int b) {
        return find(a) == find(b);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (rank[pa] == rank[pb]) {
            rank[pa]++;
            p[pb] = pa;
        } else if (rank[pa] < rank[pb]) {
            p[pa] = pb;
        } else {
            p[pb] = pa;
        }
    }
};

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M, C;
        scanf("%d %d", &M, &C);

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq;
        UnionFind uf(C);

        int num_of_pairs = (C * (C-1)) / 2;

        for (int i = 0; i < num_of_pairs; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            pq.push({c, {a, b}});
        }



        int paired = 0;
        int milk = C;

        while (paired < C - 1) {
            auto u = pq.top(); pq.pop();


            if (!uf.isSameSet(u.second.first, u.second.second)) {
                milk += u.first;
                uf.unite(u.second.first, u.second.second);
                paired++;
            }
        }

        if (M - milk >= 0) {
            printf("yes\n");
        } else {
            printf("no\n");
        }

        
    }

    return 0;
}