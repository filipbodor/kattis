#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> p;
    vector<int> rank;
    vector<long long> sums;
    vector<int> elements;
    vector<int> next;
public: 
    UnionFind(int n) {
        p.assign(n+1, 0); for (int i = 0; i <= n; i++) p[i] = i;
        rank.assign(n+1, 1);
        sums.assign(n+1, 0); for (long long i = 0; i <= n; i++) sums[i] = i;
        elements.assign(n+1, 1);
        next.assign(n+1, 1); for (int i = 0; i <= n; i++) next[i] = i;
    }

    int find(int n) {
        int np = next[n];
        while (np != p[np]) {
            np = p[np];
        }
        next[n] = np;
        return np;
    }

    void unionn(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;
        if (rank[pa] == rank[pb]) rank[pa]++;
        if (rank[pa] >= rank[pb]) {
            p[pb] = pa;
            sums[pa] += sums[pb];
            elements[pa] += elements[pb];
            next[a] = pb;
        } else {
            p[pa] = pb;
            sums[pb] += sums[pa];
            elements[pb] += elements[pa];
            next[b] = pa;
        }
    }

    void move(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        
        next[a] = pb;

        sums[pb] += a;
        sums[pa] -= a;

        elements[pb]++;
        elements[pa]--;

    }

    long long getSum(int a) {
        return sums[find(a)];
    }

    int getElements(int a) {
        return elements[find(a)];
    }
};


int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        UnionFind uf(n);
        for (int i = 0; i < m; i++) {
            int a, p, q;
            scanf("%d", &a);

            if (a == 1) {
                scanf("%d %d", &p, &q);
                uf.unionn(p, q);
            } else if (a == 2) {
                scanf("%d %d", &p, &q);
                uf.move(p, q);
            } else {
                scanf("%d", &p);
                printf("%d %ld\n", uf.getElements(p), uf.getSum(p));
            }
        }
    }



    return 0;
}