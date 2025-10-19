#include <bits/stdc++.h>
using namespace std;

#define INF 10e15
typedef long long ll;

vector<ll> S;
vector<ll> D;
int N;

int main() {
    int T;
    scanf("%d %d", &N, &T);

    S.assign(N+1, 0);
    D.assign(N+1, 0);
    S[0] = 1;
    D[0] = 1;

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &S[i], &D[i]);
    }

    
    return 0;
}