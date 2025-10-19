#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, m;
    scanf("%d %d %d", &n, &p, &m);

    vector<string> names(n);
    unordered_map<string, int> scores;
    unordered_map<string, int> winners;
    bool isWinner = false;

    for (int i = 0; i < n; i++) {
        char name[25];
        scanf("%s", &name);
        names[i] = name;
        scores[name] = 0;
    }

    for (int i = 0; i < m; i++) {
        char name[25];
        int score;
        scanf("%s %d", &name, &score);

        scores[name] += score;

        if (scores[name] >= p) {
            isWinner = true;
            if (winners[name] == 0) {
                winners[name] = 1;
                printf("%s wins!\n", name);
            }
        }
    }

    if (!isWinner) printf("No winner!\n");



    return 0;
}