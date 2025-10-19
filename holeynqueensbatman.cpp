#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;

vector<int> ocu;

int OK;

void bt(int rw, int dl, int dr, int depth) {
    if (rw == OK) { ans++; return; }
    int pos = OK & (~(rw | dl | dr | ocu[depth]));
    while (pos) {
        int p = pos & -pos;
        pos -= p;
        bt(rw|p, (dl|p) << 1, (dr|p) >> 1, depth+1);
    }
}

int main() {
    
    
    while (scanf("%d %d", &n, &m) == 2 && !(n == 0 && m == 0)) {
        ocu.assign(n, 0);
        OK = ((1 << n) - 1);
        ans = 0;

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            ocu[a] |= (1 << b);
        }

        bt(0, 0, 0, 0);
        printf("%d\n", ans);
    }

    


    return 0;
}