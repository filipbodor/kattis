#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> visited;
vector<pair<int, int>> pointsS;
vector<pair<int, int>> pointsT;
vector<string> grid;
vector<vector<int>> gridX;
vector<pair<int, int>> axes {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n;
int f;


bool dfs(int depth, int x, int y, int type) {
    //printf("depth=%d, x=%d, y=%d, type=%d\n", depth, x, y, type);

    visited[x][y] = 1;
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (auto &[p, q] : axes) {
        int xp = x + p, yp = y + q;
        if (xp >= 0 && xp < 4 && yp >= 0 && yp < 4) {
            if (pointsT[type].first == xp && pointsT[type].second == yp) {
                if (type == n - 1) {
                    visited[x][y] = -1;
                    return depth == f; 
                }
                else {
                    if (dfs(depth, pointsS[type + 1].first, pointsS[type + 1].second, type + 1)) return true;
                }
            } else if (gridX[xp][yp] == -1 && visited[xp][yp] == -1) {
                if (dfs(depth+1, xp, yp, type)) return true;
            }
        } 
    }
    visited[x][y] = -1;

    return false;
}

int main() {
    grid.assign(4, "");
    cin >> grid[0] >> grid[1] >> grid[2] >> grid[3];

    unordered_map<char, int> idx;
    vector<char> typs {};
    pointsS.assign(4, {});
    pointsT.assign(4, {});

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] != 'W' && idx.find(grid[i][j]) == idx.end()) {
                idx[grid[i][j]] = typs.size();
                typs.push_back(grid[i][j]);
                pointsS[idx[grid[i][j]]] = {i, j};
            } else if (grid[i][j] != 'W') {
                pointsT[idx[grid[i][j]]] = {i, j};
            }
        }
    }

    gridX.assign(4, vector<int>(4, -1));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gridX[i][j] = grid[i][j] == 'W' ? -1 : idx[grid[i][j]];
        }
    }

    visited.assign(4, vector<int>(4, -1));

    n = typs.size();
    f = 16 - n - n;

    if (dfs(0, pointsS[0].first, pointsS[0].second, 0)) cout << "solvable" << endl;
    else cout << "not solvable" << endl;


    return 0;
}