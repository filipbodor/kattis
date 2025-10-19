#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        int idx = 0;

        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);

            if (a == idx + 1) idx++;
        }

        printf("%d\n", n - idx);
    }

    return 0;
}