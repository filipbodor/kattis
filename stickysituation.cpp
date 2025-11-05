#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<long long> stc(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &stc[i]);
    }


    sort(stc.begin(), stc.end());

    int flag = true;
    for (int i = 0; i < n - 2 && flag; i++) {
        if (stc[i] + stc[i+1] > stc[i+2]) {
            flag = false;
        }
    }

    if (!flag) {
        printf("possible\n");
    } else {
        printf("impossible\n");
    }


    return 0;
}