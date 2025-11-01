#include <bits/stdc++.h>
using namespace std;

int OK = (1 << 26) - 1;
int n;
vector<string> wss;
vector<int> iws;


long long backtrack(int depth, int taken) {
    if (depth == n) return (taken ^ OK) == 0;

    return backtrack(depth + 1, taken | iws[depth]) + backtrack(depth + 1, taken);
}

int main() {
    scanf("%d", &n);

    wss.assign(n, "");
    iws.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> wss[i];

        for (int j = 0; j < wss[i].size(); j++) {
            iws[i] |= 1 << (wss[i][j] - 'a');  
        }
    }

    long long ans = backtrack(0, 0);
    cout << ans << endl;


    return 0;
}