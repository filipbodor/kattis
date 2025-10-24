#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

vector<vector<int>> AL;
ll mem[105];

ll topDown(int type) {
    if (AL[type].size() == 1) return AL[type][0];

    ll &ans = mem[type];
    if (ans != -1) return ans;

    ans = 0;
    for (int i : AL[type]) {
        ans += topDown(i);
    }
    return ans;
}

int main() {
    int T;
    scanf(" %d ", &T);

    while (T--) {
        scanf(" %d ", &n);

        AL.assign(n+1, {});
        unordered_map<int, int> idxs;
        vector<int> ints {};

        for (int i = 0; i < n; i++) {
            int a;
            char b[30];
            scanf(" %d %s", &a, &b);

            if (idxs.find(a) == idxs.end()) {
                ints.push_back(a);
                idxs[a] = ints.size();
            }

            if (b[0] >= '0' && b[0] <= '9') {
                int c = 0;
                for (int j = 0; j < 20 && b[j] >= '0' && b[j] <= '9'; j++) {
                    c = c * 10 + b[j] - '0';
                }
                int d, e;
                scanf(" %d  %d ", &d, &e);


                if (idxs.find(c) == idxs.end()) {
                    ints.push_back(c);
                    idxs[c] = ints.size();
                }


                if (idxs.find(d) == idxs.end()) {
                    ints.push_back(d);
                    idxs[d] = ints.size();
                }

                if (idxs.find(e) == idxs.end()) {
                    ints.push_back(e);
                    idxs[e] = ints.size();
                }

                AL[idxs[a]].push_back(idxs[c]);
                AL[idxs[a]].push_back(idxs[d]);
                AL[idxs[a]].push_back(idxs[e]);
            } else {
                AL[idxs[a]].push_back((b[0] == 'f' ? 1 : 0));
            }
        }


        memset(mem, -1, sizeof(mem));
        ll cntFa = topDown(idxs[1]);

        printf("%ld\n", cntFa);
    }

    return 0;
}