#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, n;
    scanf("%d %d", &w, &n);

    vector<int> wis(n+2);
    wis[0] = 0;
    wis[n+1] = w;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &wis[i]);
    }

    set<int> ls;


    for (int i = 0; i < n + 1; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            ls.insert(wis[j] - wis[i]);
        }
    } 

    for (auto it = ls.begin(); it != ls.end(); it++) {
        printf("%d ", *it);
    }

    return 0;
}