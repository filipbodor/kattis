#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int w, h, n;
        scanf("%d %d %d", &w, &h, &n);

        int p1Count = 0, p2Count = 0;

        vector<vector<char>> p1(h, vector<char>(w));
        vector<vector<char>> p2(h, vector<char>(w));
        char c;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf(" %c", &c);
                if (c == '#') p1Count++;
                p1[h - i - 1][j] = c;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf(" %c", &c);
                if (c == '#') p2Count++;
                p2[h - i - 1][j] = c;
            }
        }

        int a, b;
        int turn = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;

            if (flag) continue;

            if (turn == 0) {
                if (p2[b][a] == '#') {
                    p2[b][a] = '_';
                    p2Count--;
                    if (p2Count == 0) turn = 1 - turn;
                } else {
                    turn = 1 - turn;
                }
            } else {
                if (p1[b][a] == '#') {
                    p1[b][a] = '_';
                    p1Count--;
                    if (p1Count == 0) flag = true;
                } else {
                    turn = 1 - turn;

                    if (p1Count == 0 || p2Count == 0) {
                    flag = true;
                    }
                }   
            }
        }


        if (p1Count == 0 && p2Count > 0) {
            printf("player two wins\n");
        } else if (p1Count > 0 && p2Count == 0) {
            printf("player one wins\n");
        } else {
            printf("draw\n");
        }
    }

    return 0;
}