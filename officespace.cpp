#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    point() { x = y = 0; }
    point(int _x, int _y) : x(_x), y(_y) {}
};

int main() {
    int w, h, n;
    while (scanf("%d %d %d", &w, &h, &n) != EOF) {

        unordered_map<string, int> idxs;
        vector<string> names(n);
        vector<pair<point, point>> pts(n);

        for (int i = 0; i < n; i++) {
            char a[30];
            int x1, y1, x2, y2;
            scanf("%s %d %d %d %d", &a, &x1, &y1, &x2, &y2);
            names[i] = a;
            pts[i] = {point(x1, y1), point(x2, y2)};
            idxs[names[i]] = i;
        }


        int tot = w*h;
        int un = 0;
        int con = 0;
        vector<int> cnt(n, 0);

        vector<vector<int>> grid(h, vector<int>(w, 0));

        for (int i = 0; i < n; i++) {
            for (int j = pts[i].first.y; j < pts[i].second.y; j++) {
                for (int k = pts[i].first.x; k < pts[i].second.x; k++) {
                    if (grid[j][k] == 0) grid[j][k] = i + 1;
                    else grid[j][k] = -1;
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == -1) con++;
                else if (grid[i][j] == 0) un++;
                else cnt[grid[i][j]-1]++;
            }
        }

        printf("Total %d\n", tot);
        printf("Unallocated %d\n", un);
        printf("Contested %d\n", con);
        for (int i = 0; i < n; i++) {
            printf("%s %d\n", names[i].c_str(), cnt[i]);
        }
        printf("\n");
    }

    return 0;
}