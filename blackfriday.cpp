#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int l[7] = {0, -1, -1, -1, -1, -1, -1};

    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);

        if (l[a] == -1) l[a] = i;
        else l[a] = -2;
    }

    bool flag = true;
    for (int i = 6; i > 0 && flag; i--) {
        if (l[i] > 0) {
            printf("%d\n", l[i]);
            flag = false;
        }
    }

    if (flag) {
        printf("none\n");
    }

    return 0;
}