#include <bits/stdc++.h>
using namespace std;

int n; 
vector<long double> ad;
vector<long double> sol;

long double backtracking(int depth, long double sols, int took) {
    //printf("%d %Lf %d\n", depth, sols, took);
    if (depth == n) return ((sols + ad[took]) /(long double)took);

    return max(backtracking(depth+1, sols+sol[depth], took+1), backtracking(depth+1, sols, took));
}

int main() {
    scanf("%d", &n);

    ad.assign(n+1, 0);
    sol.assign(n, 0);
    
    for (int i = 1; i <= n; i++) {
        scanf("%Lf", &ad[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%Lf", &sol[i]);
    }

    long double res = backtracking(0, 0, 0);

    printf("%Lf\n", res);



    return 0;
}