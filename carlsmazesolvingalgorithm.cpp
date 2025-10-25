#include <bits/stdc++.h>
using namespace std;

int r, c, s1, s2, t1, t2;
vector<vector<int>> grid;
vector<pair<int, int>> axes {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
unordered_map<int, unordered_map<char, int>> cha {{0, {{'l', 1}, {'r', 3}}}, {2, {{'l', 3}, {'r', 1}}}, {1, {{'l', 2}, {'r', 0}}}, {3, {{'l', 0}, {'r', 2}}}};

bool inside(int x, int y) {
    return (x >= 0 && x < r && y >= 0 && y < c);
}

vector<vector<vector<int>>> memo;

bool bfs() {
    int curDir = 1;
    int curX = s1-1, curY = s2-1;

    while (!(curX == t1 -1 && curY == t2-1)) {

        //printf("%d %d %d\n", curDir, curX, curY);

        if (memo[curX][curY][curDir] != -1) {
            return 0;
        }
        memo[curX][curY][curDir] = 1;


        int leftX = curX + axes[cha[curDir]['l']].first, leftY = curY + axes[cha[curDir]['l']].second;
        if (inside(leftX, leftY) && grid[leftX][leftY] == 0) {
            curDir = cha[curDir]['l'];
            curX = leftX;
            curY = leftY;
            continue;
        } 
        int forX = curX + axes[curDir].first, forY = curY + axes[curDir].second;
        if (inside(forX, forY) && grid[forX][forY] == 0) {
            curX = forX;
            curY = forY;
            continue;
        } 

        curDir = cha[curDir]['r'];
    }

    return 1;
}

int main() {
    scanf("%d %d %d %d %d %d", &r, &c, &s1, &s2, &t1, &t2);

    grid.assign(r, vector<int>(c, 0));


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char co;
            scanf(" %c", &co);
            grid[i][j] = co == '1';
        }
    }


    memo.assign(r, vector<vector<int>>(c, vector<int>(4, -1)));

    int ans = bfs();
    printf("%d\n", ans);



    return 0;
}