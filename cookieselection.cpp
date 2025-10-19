#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
    char a;
    int i = 0;

    ost tree;

    while (scanf(" %c", &a) != EOF) {
        //printf("%c\n", a);
        if (a == '#')  {
            if ((int)tree.size() % 2 == 1) {
                printf("%d\n", (*tree.find_by_order((int)tree.size() / 2)).first);
                tree.erase(*tree.find_by_order((int)tree.size() / 2));
            } else {
                printf("%d\n", (*tree.find_by_order((int)tree.size() / 2)).first);
                tree.erase(*tree.find_by_order((int)tree.size() / 2));
            }
        } else {
            int b = a - '0';
            while (scanf("%c", &a) == 1) {
                if (a >= '0' && a <= '9') {
                    b = b * 10 + (a - '0');
                } else {
                    break;
                }
            }
            tree.insert({b, i});
        }

        i++;
        

    }

    return 0;
}
