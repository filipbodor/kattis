#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        vector<vector<int>> am(n, vector<int>());
        vector<int> pri(n);

        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);

            am[i].assign(k, 0);

            for (int j = 0; j < k; j++) {
                scanf("%d", &am[i][j]);
            }
            scanf("%d", &pri[i]);
        }

        vector<int> mm(m);
        for (int i = 0; i < m; i++) scanf("%d", &mm[i]);


        int counter = 0;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            while (flag) {
                for (int j = 0; j < (int)am[i].size() && flag; j++) {
                    flag = mm[am[i][j]-1] > 0;
                }
                if (flag) {
                    for (int j = 0; j < (int)am[i].size() && flag; j++) mm[am[i][j]-1]--;
                    counter += pri[i];
                } 
            }
        }

        printf("%d\n", counter);
    }

    return 0;
}