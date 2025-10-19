#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);


    int c = ((b + 360) - a) % 360;

    if (c > 180) {
        printf("%d\n", c - 360);
    } else {
        printf("%d\n", c);
    }


    return 0;
}