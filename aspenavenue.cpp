#include <bits/stdc++.h>
using namespace std;

int n, l, w;
double offset;
vector<double> trees;
vector<vector<double>> memo;

double dp(int type, int left) {
    if (type == n) return (type / 2 == left) ? 0 : 1e9;
    int right = type - left;

    double &ans = memo[type][left];
    if (ans != -1.0) return ans;
 
    return ans = min(abs((double)left * offset - (double)trees[type]) + dp(type + 1, left + 1), hypot((double)right * offset - (double)trees[type], (double)w) + dp(type + 1, left));
}


int main() {
    scanf("%d %d %d", &n, &l, &w);
    offset = (double)l / ((double)n / 2.0 - 1);

    trees.assign(n, 0);
    for (double &i : trees) {
        scanf("%lf", &i);
    }
    sort(trees.begin(), trees.end());

    memo.assign(n, vector<double>(n, -1.0));

    double ans = dp(0, 0);
    printf("%lf\n", ans);



    return 0;
}