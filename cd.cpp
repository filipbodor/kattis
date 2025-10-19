#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && !(n == 0 && m == 0)) {
        unordered_set<int> cds;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            cds.insert(a);
        }
        int counter = 0;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            if (cds.count(a) != 0) {
                counter++;
            }
        }

        printf("%d\n", counter);
    }


    return 0;
}