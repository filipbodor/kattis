#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n;
    scanf("%ld", &n);

    vector<long long> v(1e6);
    int c = 0;


    for (long long i = 1; i*i <= n; i++) if (n % i == 0) {
        printf("%ld ", i - 1);
        v[c] = i;
        c++;
    }

    for (int i = c - 1; i >= 0; i--) {
        if (v[i] * v[i] != n) printf("%ld ", n / v[i] - 1);
    }



    return 0;

}