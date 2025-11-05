#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) == 3 && !(a == 0 && b == 0 && c == 0)) {
        if (hypot(a, b) == c || hypot(a, c) == b || hypot(b, c) == a) {
            printf("right\n");
        } else {
            printf("wrong\n");
        }
    }
    return 0;


}