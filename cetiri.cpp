#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(3);
    scanf("%d %d %d", &a[0], &a[1], &a[2]);

    sort(a.begin(), a.end());


    if (a[1] - a[0] == a[2] - a[1]) {
        printf("%d\n", a[2] + a[2] - a[1]);
    } else if (a[1] - a[0] > a[2] - a[1]) {
        printf("%d\n", a[0] + a[2] - a[1]);
    } else {
        printf("%d\n", a[1] + a[1] - a[0]);
    }
    




    return 0;
}