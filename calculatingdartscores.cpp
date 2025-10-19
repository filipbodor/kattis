#include <bits/stdc++.h>
using namespace std;


vector<int> d;
int memo[181][60];
int parent[181];

int dp(int type, int p, int diff) {
    if (diff == 0) return 1;
    if (type == d.size() || diff < 0 || p >= 3) return 0;
    
    int &ans = memo[diff][type];
    if (ans != -1) return ans;

    if (dp(type, p + 1, diff - d[type])) {
        parent[diff] = diff - d[type];
        return ans = 1;
    }

    return ans = dp(type + 1, p, diff); 
}

int main() {
    vector<int> p(61, 0);

    for (int i = 1; i <= 20; i++) {
        p[i] = 1;
        p[i * 2] = 1;
        p[i * 3] = 1;
    }

    for (int i = 1; i <= 60; i++) {
        if (p[i]) d.push_back(i);
    }

    sort(d.rbegin(), d.rend());

    int n;
    scanf("%d", &n);

    memset(memo, -1, sizeof(memo));

    int a = dp(0, 0, n);

    if (a) {
        int t = n;
        while (t != 0) {
            int l = t - parent[t];
            if (l <= 20) printf("single %d\n", l);
            else if (l % 2 == 0 && l / 2 <= 20) printf("double %d\n", l / 2);
            else if (l % 3 <= 0 && l / 3 <= 20) printf("triple %d\n", l / 3);

            t = parent[t];
        }
    } else {
        printf("impossible\n");
    }



    return 0;
}

