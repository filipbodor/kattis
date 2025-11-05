#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    if (a == c) {
        printf("%d ", e);
    } else if (a == e) {
        printf("%d ", c);
    } else if (c == e) {
        printf("%d ", a);
    }
    if (b == d) {
        printf("%d\n", f);
    } else if (b == f) {
        printf("%d\n", d);
    } else if (d == f) {
        printf("%d\n", b);
    }

    return 0;
}