#include <bits/stdc++.h>
using namespace std;

int x, y, n;
vector<int> ops;
vector<pair<int, int>> axes {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
unordered_map<int, unordered_map<int, int>> turns {{0, {{1, 3}, {-1, 2}}}, {1, {{1, 2}, {-1, 3}}}, {2, {{1, 0}, {-1, 1}}}, {3, {{1, 1}, {-1, 0}}}};

bool works(int type, int to) {
    int cur = 0;
    int curX = 0;
    int curY = 0;


    for (int i = 0; i < n; i++) {
        int com = type == i ? to : ops[i];

        if (com == 0) {
            curX += axes[cur].first;
            curY += axes[cur].second;
        } else {
            cur = turns[cur][com];
        }
    }

    //printf("%d %d %d %d\n", type, to, curX, curY);
    return (curX == x && curY == y);

}

int main() {
    scanf("%d %d %d", &x, &y, &n);

    ops.assign(n, 0);
    for (int i = 0; i < n; i++) {
        char a[10];
        scanf("%s", &a);

        string aa = a;
        if (aa == "Left") ops[i] = -1;
        else if (aa == "Right") ops[i] = 1;
        else ops[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = -1; j <= 1; j++) if (ops[i] != j) {
            //printf("%d %d\n", i, j);
            if (works(i, j)) { printf("%d %s\n", i+1, j == -1 ? "Left" : (j == 0 ? "Forward" : "Right")); return 0; }
        }
    }

    return 0;
}