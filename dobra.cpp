#include <bits/stdc++.h>
using namespace std;

vector<int> si;
vector<int> pos {};
int n, m;
long long memo[101][3][4][4];

long long dp(int p, bool L) {
    if (p == m) return L;

    long long &ans = memo[p][L][pos[p] == 0 ? 2 : si[pos[p] - 1]][pos[p] <= 1 ? 2 : si[pos[p] - 2]];
    if (ans != -1) return ans;

    ans = 0;


    if ((n < 3) || (!(pos[p] - 1 >= 0 && pos[p] + 1 < n && si[pos[p]-1] == 0 && si[pos[p]+1] == 0) && !(pos[p] - 2 >= 0 && si[pos[p]-2] == 0 && si[pos[p]-1] == 0) && !(pos[p] + 2 < n && si[pos[p]+1] == 0 && si[pos[p]+2] == 0))) {
        si[pos[p]] = 0;
        ans += 5 * dp(p + 1, L);
        si[pos[p]] = -1;
    }
    if ((n < 3) || (!(pos[p] - 1 >= 0 && pos[p] + 1 < n && si[pos[p]-1] == 1 && si[pos[p]+1] == 1) && !(pos[p] - 2 >= 0 && si[pos[p]-2] == 1 && si[pos[p]-1] == 1) && !(pos[p] + 2 < n && si[pos[p]+1] == 1 && si[pos[p]+2] == 1))) {
        si[pos[p]] = 1;
        if (L) {
            ans += 21 * dp(p + 1, L);
        } else {
            ans += dp(p + 1, true);
            ans += 20 * dp(p + 1, false);
        }
        si[pos[p]] = -1;
    }
    

    return ans;

}

int main() {
    string a;
    cin >> a;

    n = a.size();

    bool l = false;
    si.assign(n, 0);

    for (int i = 0; i < n; i++) {
        if (a[i] == 'L') l = true;
        if (a[i] == '_') {
            si[i] = -1;
            pos.push_back(i);
        } else if (a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U') {
            si[i] = 0;
        } else {
            si[i] = 1;
        }
    }

    m = pos.size();

    memset(memo, -1, sizeof(memo));

    long long res = dp(0, l);

    cout << res << endl;


    return 0;
}