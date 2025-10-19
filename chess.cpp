#include <bits/stdc++.h>
using namespace std;

void addTable(vector<pair<int, int>> &p, int a, int b, int velA, int velB) {
    int x = a + velA, y = b + velB;
    while (1 <= x && x <= 8 && 1 <= y && y <= 8) {
        p.push_back({x, y});
        x += velA;
        y += velB;
    }
}

vector<pair<int, int>> makeTable(int a, int b) {
    vector<pair<int, int>> p {{a, b}};
    int x = a - 1, y = b - 1;
    addTable(p, a, b, -1, -1);
    addTable(p, a, b, 1, -1);
    addTable(p, a, b, -1, 1);
    addTable(p, a, b, 1, 1);
    return p;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int a, b, c, d;
        char ca, cc;
        scanf(" %c  %d  %c  %d", &ca, &b, &cc, &d);

        a = ca - 'A' + 1;
        c = cc - 'A' + 1;

        if ((a + b) % 2 != (c + d) % 2) {
            printf("Impossible\n");
            continue;
        } else if (a == c && b == d) {
            printf("0 %c %d\n", a + 'A' - 1, b);
        } else if (abs(a - c) == abs(b - d)) {
            printf("1 %c %d %c %d\n", a + 'A' - 1, b, c + 'A' - 1, d);
        } else {
            auto p1 = makeTable(a, b);
            auto p2 = makeTable(c, d);

            int x = -1, y = -1;
            

            for (int i = 0; i < (int)p1.size() && x == -1; i++) {
                for (int j = 0; j < (int)p2.size(); j++) {
                    if (p1[i] == p2[j]) {
                        x = p1[i].first;
                        y = p1[i].second;
                        break;
                    }
                }
            }

            printf("2 %c %d %c %d %c %d\n", a + 'A' - 1, b, x + 'A' - 1, y, c + 'A' - 1, d);
        }



    }

    return 0;
}