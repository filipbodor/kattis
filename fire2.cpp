#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<int>> visited;

vector<pair<int, int>> axes {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int w, h;
        scanf(" %d %d", &w, &h);

        grid.assign(h, vector<char>(w));
        visited.assign(h, vector<int>(w, -1));

        queue<pair<int, int>> qfire;
        queue<pair<int, int>> qhuman;


        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf(" %c", &grid[i][j]);
                if (grid[i][j] == '*') qfire.push({i, j});
                else if (grid[i][j] == '@') qhuman.push({i, j}), grid[i][j] = '.';
            }
        }

        bool flag = true;
        int idx = 0;

        while (flag && !qhuman.empty()) {
            idx++;
            int size = qfire.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> a = qfire.front(); qfire.pop();

                for (auto &[p, q] : axes) {
                    if (a.first + p >= 0 && a.first + p < h && a.second + q >= 0 && a.second + q < w && grid[a.first + p][a.second + q] == '.') {
                        grid[a.first + p][a.second + q] = '*';
                        qfire.push({a.first + p, a.second + q});

                    }
                }
            }

            size = qhuman.size();
            for (int i = 0; i < size && flag; i++) {     
                pair<int, int> a = qhuman.front(); qhuman.pop();
                visited[a.first][a.second] = 1;

                for (auto &[p, q] : axes) {
                    if (!(a.first + p >= 0 && a.first + p < h && a.second + q >= 0 && a.second + q < w)) {
                        flag = false;
                    } else if (a.first + p >= 0 && a.first + p < h && a.second + q >= 0 && a.second + q < w && grid[a.first + p][a.second + q] == '.' && visited[a.first + p][a.second + q] == -1) {
                        qhuman.push({a.first + p, a.second + q});
                    }
                }
            }
        }


        if (!flag) {
            printf("%d\n", idx);
        } else {
            printf("IMPOSSIBLE\n");
        }        

    }

    return 0;
}