#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> dif(51, 0);
    for (int i = 0 ; i < n; i++) {
        int a;
        scanf("%d", &a);
        dif[a] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= 50; i++) {
        cnt += dif[i];
    }

    printf("%d\n", min(k, cnt));


    return 0;
}