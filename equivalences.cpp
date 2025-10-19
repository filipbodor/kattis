#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<vector<int>> AL_T;
vector<int> dfs_num;
vector<int> S;
vector<int> in;
vector<int> out;
vector<int> ne;

int inC, outC;


void kosaraju(int u, int pass, vector<int> &le) {
    dfs_num[u] = 1;
    vector<int> &nei = (pass == 1) ? AL[u] : AL_T[u];

    inC += in[u], outC += out[u];
    le.push_back(u);
    ne[u] = 1;
 
    for (int &i : nei) {
        if (dfs_num[i] == -1) {
            kosaraju(i, pass, le);
        }
    }
    S.push_back(u);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        AL.assign(n + 1, {});
        AL_T.assign(n + 1, {});
        dfs_num.assign(n + 1, -1);
        in.assign(n + 1, 0);
        out.assign(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            AL[a].push_back(b);
            AL_T[b].push_back(a);
            out[a]++;
            in[b]++;
        }

        S.clear();
        for (int u = 1; u <= n; u++) {
            if (dfs_num[u] == -1) {
                vector<int> le {};
                ne.assign(n + 1, 0);
                kosaraju(u, 1, le);
            }
        }
        dfs_num.assign(n + 1, -1);

        int numSCC = 0, totInC = 0, totOutC = 0;

        for (int i = n-1; i >= 0; i--) {
            if (dfs_num[S[i]] == -1) {
                inC = 0, outC = 0;
                vector<int> le {};
                ne.assign(n + 1, 0);
                numSCC++; kosaraju(S[i], 2, le);

                for (int k : le) {
                    for (int o : AL[k]) {
                        if (ne[o] == 1) inC--, outC--; 
                    }
                }

                totInC += (inC == 0), totOutC += (outC == 0);
            }
        }

        if (numSCC == 1) printf("0\n");
        else printf("%d\n", max(totInC, totOutC));

    }

    return 0;
}