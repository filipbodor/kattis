#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        long long c = 0;

        ost tree;

        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            tree.insert({a, i});
            

            if (i % 2 == 1) {
                c += (*tree.find_by_order(i / 2)).first;
            } else {
                c += (double)((*tree.find_by_order(i / 2)).first + (*tree.find_by_order(i / 2 - 1)).first) / 2.0;
            }
        }

        printf("%ld\n", c);
    }
    return 0;
}