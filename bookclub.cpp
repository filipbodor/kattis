#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL; 
vector<int> vis; 
vector<int> l; 
vector<int> r; 

bool Aug(int L) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (auto &R : AL[L]) {
        if ((r[R] == -1) || Aug(r[R])) {
            l[L] = R;
            r[R] = L;
            return 1;
        }
    }

    return 0;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    AL.assign(N, {});

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        AL[a].push_back(b);
    }

    l.assign(N, -1);
    r.assign(N, -1);

    int matched = true;

    while (matched) {
        matched = false;
        vis.assign(N, 0);
        for (int L = 0; L < N; L++) if (l[L] == -1) {
            matched |= Aug(L);
        }
    }

    bool flag = true;

    for (int i = 0; i < N && flag; i++) {
        if (l[i] == -1) {
            printf("NO\n");
            flag = false;
        }
    }

    if (flag) printf("YES\n"); 

    return 0;
}