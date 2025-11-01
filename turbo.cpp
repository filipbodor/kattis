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

    unordered_map<int, int> idxs;
};

int main() {
    int n;
    scanf("%d", &n);

    FenwickTree ft(n+1);

    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        ft.update(i, 1);
        ft.idxs[a] = i;
    } 

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            printf("%d\n", ft.rsq(ft.idxs[(i / 2) + 1]) - 1);
            ft.update(ft.idxs[(i / 2) + 1], -1);
        } else {
            printf("%d\n", ft.rsq(ft.idxs[n - (i / 2)], n) - 1);
            ft.update(ft.idxs[n - (i / 2)], -1);
        }
    }

    


    return 0;
}