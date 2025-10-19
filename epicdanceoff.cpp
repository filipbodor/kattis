#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ans = 1;

    vector<string> am(n);

    for (int i = 0; i < n; i++) {

        cin >> am[i];
    }

    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (int j = 0; j < n && flag; j++) {
            flag = am[j][i] == '_';
        }
        if (flag) ans++;
    }

    cout << ans << endl;

    return 0;
}