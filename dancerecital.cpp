#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

int memo[11][1 << 11];

vector<int> alp(26, 0);
vector<vector<int>> rou;
vector<string> rou_str;

int dp(int mask, int prev) {
    if (mask == 0) return 0;

    int &ans = memo[prev][mask];
    if (ans != -1) return ans;

    ans = 1e9;
    int m = mask;

    while (m) {
        int r = LSOne(m);
        int ctz = __builtin_ctz(r);

        int ch = 0;

        if (prev != 10) {
            for (char s : rou_str[ctz]) if (rou[prev][s - 'A']) ch++;
        }

        ans = min(ans, ch + dp(mask^r, ctz));

        m -= r;
    }

    return ans;
}


int main() {
    int n;
    cin >> n;
    
    string str;

    for (int i = 0; i < n; i++) {
        cin >> str;
        vector<int> a(26, 0);

        for (char s : str) {
            a[s - 'A'] = 1;
        }

        rou.push_back(a);
        rou_str.push_back(str);
    }


    memset(memo, -1, sizeof(memo));
    int res = dp((1 << n) - 1, 10);

    cout << res << endl;
    
    return 0;

}