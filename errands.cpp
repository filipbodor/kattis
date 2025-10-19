#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

vector<string> cit;
vector<pair<double, double>> poses;
unordered_map<string, int> trans;
double AM[101][101];
double memo[12][1 << 10];
vector<string> ci;
vector<vector<pair<int, int>>> pr;


double dp(int mask, int v) {
    if (mask == 0) return AM[trans[ci[v]]][trans["home"]];

    double &ans = memo[v][mask];
    if (ans != -1) return ans;

    ans = 1e9;
    int m = mask;
    while (m != 0) {
        int p = LSOne(m);
        int pw = __builtin_ctz(p);

        double res = AM[trans[ci[v]]][trans[ci[pw]]] + dp(mask^p, pw);
        if (res < ans) {
            ans = res;
            pr[v][mask] = {pw, mask^p};
        }

        m -= p;
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    cit.assign(n, "");
    poses.assign(n, {});

    for (int i = 0; i < n; i++) {
        char a[25];
        double c, d;
        scanf("%s %lf %lf", &a, &c, &d);

        cit[i] = a;
        poses[i] = {c, d};
        trans[a] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AM[i][j] = sqrt(pow(poses[i].first - poses[j].first, 2) + pow(poses[i].second - poses[j].second, 2));
            AM[j][i] = sqrt(pow(poses[i].first - poses[j].first, 2) + pow(poses[i].second - poses[j].second, 2));
        }
    }

    char a;
    while (scanf(" %c", &a) != EOF && a != '\n') {
        string temp = "";
        ci.clear();
        
        do {
            if (a == ' ') {
                ci.push_back(temp);
                temp = "";
            } else {
                temp += a;
            }
        } while (scanf("%c", &a) != EOF && a != '\n');
        if (temp != "") ci.push_back(temp);

        int size = ci.size();
        pr.assign(size + 1, vector<pair<int, int>>(1 << 10, {0, 0}));

        ci.push_back("work");


        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < (1 << 10); j++) {
                memo[i][j] = -1;
            }
        }

        double ans = dp((1 << size) - 1, size);

        auto [curA, curB] = pr[size][(1 << size) - 1];
        for (int i = 0; i < size; i++) {
            printf("%s ", ci[curA].c_str());
            auto [cA, cB] = pr[curA][curB];
            curA = cA;
            curB = cB;
        }
        printf("\n");

        //printf("%lf %lf", ans, AM[1][2] + AM[2][3] + AM[3][4] + AM[4][0]);


    }


    return 0;
}