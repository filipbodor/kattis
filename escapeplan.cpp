#include <bits/stdc++.h>
using namespace std;

pair<double, double> pos1[205];
pair<double, double> pos2[205];

vector<int> match, vis;

int Aug(int L, vector<vector<int>> &AL) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (auto &R : AL[L]) {
        if ((match[R] == -1) || Aug(match[R], AL)) {
            match[R] = L;
            return 1;
        }
    }
    return 0;
}


double err = 1e-6;

int main() {
    int n;
    int idx = 1;
    
    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++) {
            double a, b;
            scanf("%lf %lf", &a, &b);
            pos1[i] = {a, b};
        }

        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            double a, b;
            scanf("%lf %lf", &a, &b);
            pos2[i] = {a, b};
        }

        vector<vector<int>> in5(n+m, vector<int>());
        vector<vector<int>> in10(n+m, vector<int>());
        vector<vector<int>> in20(n+m, vector<int>());


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                double t = sqrt(pow(pos1[i].first - pos2[j].first, 2) + pow(pos1[i].second - pos2[j].second, 2)) / 10.0; 

                if (t <= 5.0 + err) in5[i].push_back(j + n), in5[j + n].push_back(i);
                if (t <= 10.0 + err) in10[i].push_back(j + n), in10[j + n].push_back(i);
                if (t <= 20.0 + err) in20[i].push_back(j + n), in20[j + n].push_back(i);
            }
        }

        match.assign(n+m, -1);
        int cnt5 = 0;
        for (int L = 0; L < n; L++) {
            vis.assign(n+m, 0);
            cnt5 += Aug(L, in5);
        }

        match.assign(n+m, -1);
        int cnt10 = 0;
        for (int L = 0; L < n; L++) {
            vis.assign(n+m, 0);
            cnt10 += Aug(L, in10);
        }

        match.assign(n+m, -1);
        int cnt20 = 0;
        for (int L = 0; L < n; L++) {
            vis.assign(n+m, 0);
            cnt20 += Aug(L, in20);
        }


        printf("Scenario %d\n", idx);
        printf("In 5 seconds %d robot(s) can escape\n", cnt5);
        printf("In 10 seconds %d robot(s) can escape\n", cnt10);
        printf("In 20 seconds %d robot(s) can escape\n\n", cnt20);

        idx++;
    }

    return 0;
}