#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> AL;
vector<int> partners;
vector<int> l;
vector<int> p;

int main() {

    int C, P, X, Y;
    scanf("%d %d %d %d", &C, &P, &X, &Y);

    AL.assign(C+1, {});
    partners.assign(C+1, 0);
    l.assign(C+1, 0);
    p.assign(C+1, 0);


    for (int i = 0; i < P; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        AL[a].push_back(b);
        AL[b].push_back(a);
        partners[a]++;
        partners[b]++;
        p[a]++;
        p[b]++;
    }


    priority_queue<pair<int, int>> pq;
    pq.push({partners[Y], Y});

    while (!pq.empty() && !l[X]) {
        auto [a, b] = pq.top(); pq.pop();

        l[b] = 1;

        for (auto v : AL[b]) if (!l[v]) {
            partners[v]--;
            if (partners[v] <= (double)p[v] / 2.0) {
                pq.push({partners[v], v});
            }
        }
    }

    if (l[X]) {
        printf("leave\n");
    } else {
        printf("stay\n");
    }

    return 0;
}
