#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    char c;
    scanf("%d %c", &a, &c);

    int points = 0;

    unordered_map<char, int> dom {{'A', 11}, {'K', 4}, {'Q', 3}, {'J', 20}, {'T', 10}, {'9', 14}, {'8', 0}, {'7', 0}};
    unordered_map<char, int> ndom {{'A', 11}, {'K', 4}, {'Q', 3}, {'J', 2}, {'T', 10}, {'9', 0}, {'8', 0}, {'7', 0}};

    for (int i = 0; i < 4*a; i++) {
        char h, v;
        scanf(" %c %c", &v, &h);

        if (h == c) {
            points += dom[v];
        } else {
            points += ndom[v];
        }

    }

    printf("%d\n", points);

    return 0;
}