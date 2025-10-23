#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<double> sp;

int n;

vector<vector<pair<int, double>>> memo;

pair<int, double> dp(int type, int p, int taken) {
    if (AL[type].size() == 1 && p != -1) return {0, 0};

    pair<int, double> &ans = memo[type][taken];
    if (ans.first != -1) return ans;

    vector<pair<int, double>> me {};

    int teams = 0;
    double su = 0.0;

    for (int i : AL[type]) {
        if (i == p) {
            me.push_back({0, 0});
            continue;
        }

        me.push_back(dp(i, type, 0));
        teams += me[me.size() - 1].first;
        su += me[me.size() - 1].second;
    }


    ans = {teams, su};

    if (taken) return ans;

    for (int i = 0; i < AL[type].size(); i++) if (AL[type][i] != p) {
        auto a = dp(AL[type][i], type, 1);
        ans = max(ans, {teams - me[i].first + a.first + 1, su - me[i].second + a.second + min(sp[AL[type][i]], sp[type])});
    }

    return ans;
}

int main() {
    scanf("%d", &n);

    vector<string> names {};
    unordered_map<string, int> idxs;
    AL.assign(n+1, {});
    sp.assign(n+1, 0.0);

    for (int i = 0; i < n; i++) {
        char a[20], b[20];
        double c;
        scanf("%s %lf %s", &a, &c, &b);

        if (idxs.find(a) == idxs.end()) {
            idxs[a] = names.size();
            names.push_back(a);
        }
        if (idxs.find(b) == idxs.end()) {
            idxs[b] = names.size();
            names.push_back(b);
        }
        AL[idxs[a]].push_back(idxs[b]);
        AL[idxs[b]].push_back(idxs[a]);
        sp[idxs[a]] = c;
    }

    memo.assign(n + 1, vector<pair<int, double>>(2, {-1, -1.0}));
    auto res = dp(idxs["CEO"], -1, 1);

    printf("%d %lf\n", res.first, res.second / (double)res.first);


    return 0;
}