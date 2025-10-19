#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int id = 1;

    char idxs[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

    do {
        printf("%s ", idxs);

        id++;
    } while (next_permutation(idxs, idxs + 9) && (id <= a || id <= ceil((double)b / 2.0)));

    return 0;
}