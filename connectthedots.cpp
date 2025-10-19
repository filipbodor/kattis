#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, char> signs {{{0, 1}, '-'}, {{0, -1}, '-'}, {{1, 0}, '|'}, {{-1, 0}, '|'}};

vector<char> sis {};
unordered_map<char, int> sisscore {};

void mark(vector<vector<int>> &grid, int x, int y, int px, int py, int b) {
    x += px;
    y += py;
    while (grid[x][y] != b) {

        if (grid[x][y] == '.') {
            grid[x][y] = signs[{px, py}];
        } else if ((grid[x][y] == '-' || grid[x][y] == '|') && grid[x][y] != signs[{px, py}]) {
            grid[x][y] = '+';
        }

        x += px;
        y += py;
    }
}

int main(){
    char c;
    bool flag = true;
    for (int i = '0'; i <= '9'; i++) sis.push_back(i);
    for (int i = 'a'; i <= 'z'; i++) sis.push_back(i);
    for (int i = 'A'; i <= 'Z'; i++) sis.push_back(i);

    for (int i = 0; i < sis.size(); i++) {
        sisscore[sis[i]] = i;
    }

    while (flag) {
        vector<vector<int>> grid {};
        unordered_map<int, pair<int, int>> poses;
        char ma = 0;
        while ((flag = scanf("%c", &c) != EOF) && c != '\n') {
            grid.push_back({});
            do {
                grid[grid.size()-1].push_back(c);
                if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    poses[c] = {grid.size()-1, grid[grid.size()-1].size()-1};
                    if (sisscore[ma] < sisscore[c]) ma = c;
                }
            } while (scanf("%c", &c) == 1 && c != '\n');
        }

        for (int i = 0; i < (int)sis.size() && sisscore[sis[i]] < sisscore[ma]; i++) {
            if (poses[sis[i]].first == poses[sis[i+1]].first && poses[sis[i]].second < poses[sis[i+1]].second) {
                mark(grid, poses[sis[i]].first, poses[sis[i]].second, 0, 1, sis[i+1]);
            } else if (poses[sis[i]].first == poses[sis[i+1]].first && poses[sis[i]].second > poses[sis[i+1]].second) {
                mark(grid, poses[sis[i]].first, poses[sis[i]].second, 0, -1, sis[i+1]);
            } else if (poses[sis[i]].first < poses[sis[i+1]].first && poses[sis[i]].second == poses[sis[i+1]].second) {
                mark(grid, poses[sis[i]].first, poses[sis[i]].second, 1, 0, sis[i+1]);
            } else if (poses[sis[i]].first > poses[sis[i+1]].first && poses[sis[i]].second == poses[sis[i+1]].second) {
                mark(grid, poses[sis[i]].first, poses[sis[i]].second, -1, 0, sis[i+1]);
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");

    }

    return 0;
}