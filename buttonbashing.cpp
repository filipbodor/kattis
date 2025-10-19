#include <bits/stdc++.h>
using namespace std;

int mem[16][7200];
int mem1[3600];
vector<int> buttons;
int n, t;
int inf = 1e9;
int dp(int type, int val, int c) {
    if (type >= n) return inf;
    if (val == t) return 0;
    if (val < 0) val = 0;
    if (val >= t*2 - 1) return inf;

    if (type == n - 1 && val > t) mem1[val - t] = c;

    int &ans = mem[type][val];
    if (ans != -1) return ans;

    if (val == 0 && buttons[type] <= 0) ans = dp(type + 1, val, c);

    return ans = min(1 + dp(type, val + buttons[type], c + 1), dp(type + 1, val, c));
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &n, &t);

        buttons.assign(n, 0);
        for (int &i : buttons) {
            scanf("%d", &i);
        }


        memset(mem, -1, sizeof(mem));

        sort(buttons.rbegin(), buttons.rend());

        int mi = dp(0, 0, 0);

        if (mi >= inf) {
            for (int i = t; i < t*2; i++) {
                if (mem[n-1][i] != -1) {
                    printf("%d %d\n", mem1[i - t], i - t);
                    break;
                }
            }
        } else {
            printf("%d 0\n", mi);
        }



    }

    return 0;
}