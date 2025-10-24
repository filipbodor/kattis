#include <bits/stdc++.h>
using namespace std;

int main() {


    // for (int i = 0; i <= 2018; i++) {
    //     for (int j = 0; j <= 2018; j++) {
    //         if (hypot(i, j) == 2018) printf("%d %d\n", i, j);
    //     }
    // }



    int n;
    scanf("%d", &n);

    vector<pair<long long, long long>> points(n);

    unordered_map<int, map<int, int>> xtoy;
    unordered_map<int, map<int, int>> ytox;

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        points[i] = {a, b};
        xtoy[a][b]++;
        ytox[b][a]++;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += xtoy[points[i].first][points[i].second + 2018];
        cnt += xtoy[points[i].first][points[i].second - 2018];
        cnt += xtoy[points[i].first + 2018][points[i].second];
        cnt += xtoy[points[i].first - 2018][points[i].second];

        cnt += xtoy[points[i].first + 1118][points[i].second + 1680];
        cnt += xtoy[points[i].first - 1118][points[i].second + 1680];
        cnt += xtoy[points[i].first + 1118][points[i].second - 1680];
        cnt += xtoy[points[i].first - 1118][points[i].second - 1680];

        cnt += xtoy[points[i].first + 1680][points[i].second + 1118];
        cnt += xtoy[points[i].first - 1680][points[i].second + 1118];
        cnt += xtoy[points[i].first + 1680][points[i].second - 1118];
        cnt += xtoy[points[i].first - 1680][points[i].second - 1118];
    }
    

    printf("%d\n", cnt / 2);

    return 0;
}