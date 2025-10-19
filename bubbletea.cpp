#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, X;
    scanf("%d", &N);

    vector<int> b(N+1);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &b[i]);
    }

    scanf("%d", &M);
    vector<int> t(M+1);

    for (int i = 1; i <= M; i++) {
        scanf("%d", &t[i]);
    }


    vector<vector<int>> AL(N+1);
    for (int i = 1; i <= N; i++) {
        int a;
        scanf("%d", &a);
        AL[i].assign(a, -1);
        for (int &j : AL[i]) {
            scanf("%d", &j);
        }
    }

    scanf("%d", &X);

    int mi = 1e9 + 10;

    for (int i = 1; i <= N; i++) {
        for (int &j : AL[i]) {
            mi = min(mi, b[i] + t[j]);
        }
    }

    int number = X / mi;

    number -= 1;
    
    if (number < 0) number = 0;


    printf("%d\n", number);
    


    return 0;
}