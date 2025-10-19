#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<int> visited;

vector<long long> fib_nums;
unordered_map<long long, int> nums_fibs;
vector<long long> fibs;

int memo[100001];

int dfs(int u, bool prev) {

    int &ans = memo[u];
    if (ans != -1 && fibs[u] != 1) return ans;

    ans = 0;
    for (int i : AL[u]) if (!(fibs[i] == 1 && fibs[u] == 1 && prev)) {
        ans = max(ans, dfs(i, fibs[u] == 1));
    }
    ans++;

    return ans;
}

void makeFibs() {

    fib_nums = {1, 1};
    nums_fibs[1] = 1;
    int idx = 2;

    while (fib_nums[idx-1] + fib_nums[idx-2] <= 1e18) {
        nums_fibs[fib_nums[idx-1] + fib_nums[idx-2]] = idx;
        fib_nums.push_back(fib_nums[idx-1] + fib_nums[idx-2]);
        idx++;
    }
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    makeFibs();

    fibs.assign(n+1, 0);
    AL.assign(n+1, {});
 
    for (int i = 1; i <= n; i++) {
        long long a;
        scanf("%lld", &a);   
        if (nums_fibs.find(a) != nums_fibs.end()) fibs[i] = nums_fibs[a];
        else fibs[i] = -1;
    }

    // for (int i = 1; i <= n; i++) {
    //     printf("%d, ", fibs[i]);
    // }
    // printf("\n");

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (fibs[a] != -1 && fibs[b] != -1 && (abs(fibs[a] - fibs[b]) == 1 || (fibs[a] == 1 && fibs[b] == 1)))   {
            if (fibs[a] <= fibs[b]) AL[a].push_back(b);
            if (fibs[a] >= fibs[b]) AL[b].push_back(a);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     printf("AL %d: ", fib_nums[fibs[i]]);
    //     for (int j = 0; j < (int)AL[i].size(); j++) printf("%d ", fib_nums[fibs[AL[i][j]]]);
    //     printf("\n");
    // }

    memset(memo, -1, sizeof(memo));
    int res = -1;
    for (int i = 1; i <= n; i++) if (fibs[i] != -1) {
        res = max(res, dfs(i, false));
    }

    if (res == -1) {
        printf("0\n");
    } else {
        printf("%d\n", res);
    }





    return 0;
}