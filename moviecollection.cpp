#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

class FenwickTree {
private:
    vector<int> ft;
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

    void update(int j, int v) {
        for (; j < (int)ft.size(); j += LSOne(j)) {
            ft[j] += v;
        }
    }

    unordered_map<int, int> idxs;
    int size;
};


int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, r;
        scanf("%d %d", &n, &r);


        FenwickTree ft(n + r + 2);

        for (int i = r + 1; i < r + n + 1; i++) {
            //printf("%d\n", i);
            ft.update(i, 1);
            ft.idxs[i - r - 1] = i;
        }

        ft.size = r;

        for (int i = 0; i < r; i++) {
            int q;
            scanf("%d", &q);

            if (i) printf(" ");
            printf("%d", ft.rsq(ft.idxs[q-1]) - 1);

            ft.update(ft.idxs[q-1], -1);
            ft.idxs[q-1] = ft.size--;
            ft.update(ft.idxs[q-1], 1);
        }

        printf("\n");

    }

    return 0;
}