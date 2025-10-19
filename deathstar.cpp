#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> grid(n, vector<int>(n));
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans[i] |= grid[i][j];
            ans[j] |= grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");


    return 0;
}