#include <bits/stdc++.h>
using namespace std;

// not solved yet

int n, m;

vector<pair<int, int>> mas;

vector<unordered_map<string, bool>> memo;

string ans;

bool dp(int type, string diff, vector<int> &sc) {
    if (type == m) {
        for (int i = 1; i < n; i++) {
            if (sc[i] >= sc[n]) return false;
        }
        ans = diff;
        return true;
    }

    if (memo[type].find(sc) != memo[type].end()) return memo[type][sc];

    sc[mas[type].first] += 2;
    if (dp(type + 1, diff + "0 ", sc)) {
        return memo[type][sc] = true;
    }
    
    sc[mas[type].first]--;
    sc[mas[type].second]++;
    if (dp(type + 1, diff + "1 ", sc)) {
        return memo[type][sc] = true;
    }

    sc[mas[type].first]--;
    sc[mas[type].second]++;
    if (dp(type + 1, diff + "2 ", sc)) {
        return memo[type][sc] = true;
    }

    sc[mas[type].second] -= 2;

    return memo[type][sc] = false;



}

int main() {

    while (scanf("%d %d", &n, &m) == 2) {
        vector<int> scs(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &scs[i]);
        }
        mas.assign(m, {});

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            mas[i] = {a, b};
        }

        memo.assign(m, {{}, 0});

        bool res = dp(0, "", scs);

        if (res) {
            printf("%s\n", ans.c_str());
        } else {
            printf("NO\n");
        }


    }

    return 0;
}