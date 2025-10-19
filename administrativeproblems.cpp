#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    set<pair<int, int>> ints;

    for (int i = 0; i < N; i++) {
        int L, U;
        scanf("%d %d", &L, &U);
        ints.insert({L, U});
    }

    int counter = 0;
    pair<int, int> curr = {-1, -1};

    for (auto &[a, b] : ints) {
        if (a > curr.second) {
            counter++;
            curr = {a, b};
        } else if (b <= curr.second) {
            curr = {a, b};
        } else {
            curr = {a, curr.second};
        }
    }

    printf("%d\n", counter);
}