#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int AM[21];
ll OK;
int mi;

void backtrack(ll mask, int type, int taken) {
    //printf("%d %lld %d\n", type, mask, taken);
    if (type == n) { mi = min(mi, (int)((mask ^ OK) == 0 ? taken : 1e9)); return; }
    if (taken >= mi) return;

    backtrack(mask | AM[type], type + 1, taken + 1);
    backtrack(mask, type + 1, taken);
}   

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        memset(AM, 0, sizeof(AM));
        for (int i = 0; i < n; i++) {
            AM[i] = 1LL << i; 
        }
        for (int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                int a;
                scanf("%d", &a);
                AM[i] |= 1LL << (a-1);
                //AM[(a-1)] |= 1LL << i;
            }
        }

        OK = (1LL << n) - 1LL;
        mi = 1e9;

        backtrack(0, 0, 0);
        printf("%d\n", mi);



    }

    return 0;
}