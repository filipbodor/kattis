#include <bits/stdc++.h>
using namespace std;

double AM[210][210];

unordered_map<string, int> currs;

bool asas(int C) {

    for (int k = 0; k < C; k++) {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < C; j++) {
                AM[i][j] = max(AM[i][j], AM[i][k] * AM[k][j]);
            }
        }
    }

    for(int i = 0; i < C; i++) {
        if (AM[i][i] > 1.01) return true;
    } 
    return false;
}

int main() {
    int C;

    while (scanf("%d", &C) == 1 && C != 0) {
        currs.clear();

        for (int i = 0; i < C; i++) {
            char a[4];
            scanf("%s", &a);
            currs[a] = i;
        }

        for (int i = 0; i < C; i++) for (int j = 0; j < C; j++) AM[i][j] = 0.0;
        for (int i = 0; i < C; i++) AM[i][i] = 1.0;

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char a[4], b[4];
            double c, d;


            scanf("%s %s %lg:%lg", &a, &b, &c, &d);
            AM[currs[a]][currs[b]] = max(AM[currs[a]][currs[b]], d / c);
        }

        if (asas(C)) printf("Arbitrage\n");
        else printf("Ok\n");

    }

    return 0;
}