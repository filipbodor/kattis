#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class UnionFind {
private: 
    int n;
    vector<int> ch, p;
public:
    UnionFind(int n) : n(n) {
        ch.assign(n, 1);
        p.assign(n, 0); for (int i = 0; i < n; i++) p[i]= i;
    };

    int find(int a) {
        if (p[a] == a) return a;
        return p[a] = find(p[a]);
    }

    bool isSameSet(int a, int b) {
        return find(a) == find(b);
    }

    void un(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        p[pb] = pa;
        ch[pa] += ch[pb];
    }

    int getCh(int a) {
        return ch[find(a)];
    }

    void prin() {
        for (int i = 0; i < n; i++) {
            printf("%d ", p[i]);
        }
        printf("\n");
    }
};

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<long double, long double>> pairs(n);
    //priority_queue<tuple<int, long double, int>> pq;
    set<tuple<long double, long double, int>> pq;

    long double wl = 0, wr = 0;

    for (int i = 0; i < n; i++) {
        long double a, b;
        scanf("%Lf %Lf", &a, &b);

        pairs[i] = {b, a};
        if (a < 0) wl += -a * b;
        else wr += a * b;
    }

    if (wl > wr) {
        for (int i = 0; i < n; i++) {
            pairs[i] = {pairs[i].first, -pairs[i].second};
        }
        reverse(pairs.begin(), pairs.end());
        swap(wl, wr);
    }

    for (int i = 0; i < n; i++) {

        pq.insert({-pairs[i].first, pairs[i].second, i});
    }

    double long totdist = 0.0;

    // for (int i = 0; i < n; i++) {
    //     printf("%Lf %Lf, ", pairs[i].first, pairs[i].second);
    // }
    // printf("\n");

    UnionFind uf(n);

    //uf.prin();

    while (wl != wr) {
        auto it = pq.end();
        auto [a, b, c] = *pq.begin();
        pq.erase(*pq.begin());

        int dd = uf.getCh(c);

        a = -a;

        //printf("%Lf %Lf %d %d\n", a, b, c, dd);



        if (c == 0) {
            totdist += ((wr - wl) / (a));
            wr = wl; 
            //printf("a\n");
        } else {
            int r = uf.find(c-1);

            //printf("%d\n", pairs[r].second);

            auto [oo, op] = pairs[r];

            long double d = b - op;

            if (((wr - wl) / (a * dd)) <= d) {
                totdist += ((wr - wl) / (a));
                wr = wl;
                //printf("b\n");

            } else {
                //printf("c\n");
                totdist += d * dd;
                wr -= d * a * dd;



                //printf("%d\n", pq.count({-pairs[r].first, pairs[r].second, r}));
                pq.erase({-pairs[r].first, pairs[r].second, r});
                pq.insert({-(oo * uf.getCh(r) + a * dd) / (uf.getCh(r) + dd), op, r});
                
                pairs[r] = {(pairs[r].first * uf.getCh(r) + pairs[c].first * dd) / (uf.getCh(r) + dd), pairs[r].second};

                uf.un(r, c);
                
            }
        }
        //printf("%LF\n", totdist);
        //uf.prin();

        // for (int i = 0; i < n; i++) {
        //     printf("%Lf %Lf, ", pairs[i].first.first, pairs[i].first.second);
        // }
        // printf("\n");
        //uf.prin();

    }

    //uf.prin();


    printf("%Lf\n", totdist);

    

    return 0;
}