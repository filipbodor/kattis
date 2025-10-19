#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;

        scanf("%d %d", &a, &b);

        int o = (a + b) / 2;
        int l = o - b;

        if (o < 0 || l < 0 || ((a + b) % 2 == 1)) {
            printf("impossible\n");
        } else {
            printf("%d %d\n", o, l);
        }
    }

    return 0;
}