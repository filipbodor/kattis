#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef vector<int> vi;

class FenwickTree {
private:
    vi ft;
public:
    FenwickTree(int n) {
        ft.assign(n, 0);
    }

    int rsq(int j) {
        int sum = 0;
        for (; j; j -= LSOne(j)) {
            sum += ft[j];
        }
        return sum;
    }

    int rsq(int i, int j) {
        return rsq(j) - rsq(i - 1);
    }

    void update(int j, int v) {
        for (; j < (int)ft.size(); j += LSOne(j)) {
            ft[j] += v;
        }
    }
};

int main() {
    int n, r;
    scanf("%d %d", &n, &r);

    FenwickTree ft(n + 1);
    vi bits(n, -1);

    for (int i = 0; i < r; i++) {
        char a;
        scanf(" %c ", &a);
        if (a == 'F') {
            int g;
            scanf("%d", &g);
            bits[g-1] = -bits[g-1];
            ft.update(g, bits[g-1]);
        } else {
            int g, o;
            scanf("%d %d", &g, &o);
            printf("%d\n", ft.rsq(g, o));
        }
    }
    

    return 0;
}