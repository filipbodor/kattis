#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, idx = 0;
    scanf("%d", &n);


    unordered_map<string, pair<int, int>> un_cats;
    set<tuple<int, int, string>> cats;

    while (n--) {
        int a;
        scanf("%d", &a);

        if (a == 0) {
            char name[20];
            int b;
            scanf("%s %d", &name, &b);

            un_cats[name] = {b, idx};
            cats.insert({b, idx, name});

            idx--;

        } else if (a == 1) {
            char name[20];
            int b;
            scanf("%s %d", &name, &b);

            auto r = un_cats[name];
            cats.erase({r.first, r.second, name});
            cats.insert({r.first + b, r.second, name});
            un_cats[name] = {r.first + b, r.second};
        } else if (a == 2) {
            char name[20];
            scanf("%s", &name);

            auto r = un_cats[name];
            cats.erase({r.first, r.second, name});
        } else {
            if (cats.empty()) {
                printf("The clinic is empty\n");
            } else {
                auto it = cats.end();
                it--;
                auto &[o, f, g] = *it;
                printf("%s\n", g.c_str());
            }
        }
    }

    return 0;
}