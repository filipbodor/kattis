#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<long long> am(200001);

    for (long long i = 0; i <= 200000; i++) {
        am[i] = i * i;
    }

    long long a = -1, b = -1;
    for (int i = 0; i <= 200000 && a == -1; i++) {
        //printf("%d\n", am[i]);
        if (n != 2 * am[i] && binary_search(am.begin(), am.end(), am[i] - n)) {
            a = am[i] - n, b = am[i];
        }
    }

    if (a == -1) {
        printf("impossible\n");
    } else {
        printf("%d %d\n", (int)sqrt(a), (int)sqrt(b));
    }

    return 0;
}