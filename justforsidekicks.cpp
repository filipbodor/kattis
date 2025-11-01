#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define LSOne(S) ((S) & -(S))

typedef vector<int> vi;

class FenwickTree {
private:
    vi ft;
    int val;
public:
    FenwickTree(int m, int v) {
        ft.assign(m+1, 0);
        val = v;
    }

    void setVal(int v) {
        val = v;
    }

    ll rsq(int j) {
        ll sum = 0;
        for (; j; j -= LSOne(j)) {
            sum += ft[j];
        }
        return sum;
    }

    ll rsq(int i, int j) {
        return (rsq(j) - rsq(i-1)) * val;
    }

    void update(int i, int v) {
        for (; i < (int)ft.size(); i += LSOne(i)) {
            ft[i] += v;
        }
    }
};


int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    vector<ll> gems(6);
    for (ll &i : gems) {
        scanf("%lld", &i);
    }

    vector<int> s(N+1);

    for (int i = 1; i <= N; i++) {
        char a;
        scanf(" %c", &a);
        s[i] = a - '1';
    }

    vector<FenwickTree> vft;

    for (int i = 0; i < 6; i++) {
        vft.emplace_back(FenwickTree(N, gems[i]));
    }
    for (int i = 1; i <= N; i++) {
        vft[s[i]].update(i, 1);
    }



    for (int i = 0; i < Q; i++) {
        int a, b, c;
        scanf(" %d %d %d\n", &a, &b, &c);

        //printf("%d %d %d\n", a, b, c);

        if (a == 1) {
            vft[s[b]].update(b, -1);
            vft[c-1].update(b, 1);
            s[b] = c-1;
        } else if (a == 2) {
            vft[b-1].setVal(c);
        } else {
            ll sum = 0;
            for (int j = 0; j < 6; j++) {
                sum += vft[j].rsq(b, c);
            }
            printf("%lld\n", sum);
        }

    }



    return 0;
}