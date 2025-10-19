#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

int n, m, best;
vector<int> AM;


void backtrack(int type, vector<int> &state) {
    if (type == n) best = min(best, (int)state.size());
    if ((int)state.size() >= best) return;

    for (int i = 0; i < (int)state.size(); i++) {
        if (((1 << type) & state[i]) == (1 << type)) {
            int temp = state[i];
            state[i] &= (AM[type]);
            backtrack(type + 1, state);
            state[i] = temp;
        }
    }
    state.push_back(AM[type]);
    backtrack(type+1, state);
    state.pop_back();
}

int main() {

    while (scanf("%d %d", &n, &m) == 2 && !(n == 0 && m == 0)) {
        unordered_map<string, int> idxs;
        int idx = 0;
        AM.assign(n, (1 << n) - 1);
        
        for (int i = 0; i < m; i++) {
            char a[30], b[30];
            scanf("%s %s", &a, &b);
            if (idxs.find(a) == idxs.end()) idxs[a] = idx++;
            if (idxs.find(b) == idxs.end()) idxs[b] = idx++;
            AM[idxs[a]] &= ~(1 << idxs[b]);
            AM[idxs[b]] &= ~(1 << idxs[a]);
        }

        vector<int> state {};
        best = 1e9;
        backtrack(0, state);

        printf("%d\n", best);


    }

    return 0;
}