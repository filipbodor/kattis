#include <bits/stdc++.h>
using namespace std;
int a, b;
vector<pair<int, int>> axes = {{1, -1}, {1, 0}, {1, 1}, {0, 1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
vector<vector<char>> D;
vector<vector<int>> visited;

bool DFS(int x, int y) {
    visited[x][y] = 1;
    int counter = 0;

    for (auto &[p, q] : axes) {
        int px = p + x, qy = q + y;
        if (px >= 0 && px < a && qy >= 0 && qy < b) {
            if (D[px][qy] == '#') {
                counter++;
                if (visited[px][qy] == 0) {
                    if (!DFS(px, qy)) return false;
                }
            }
        }
    }

    return true;
}


int main() {
    scanf("%d %d", &a, &b);
    
    D.assign(a, vector<char>(b, 0));
    visited.assign(a, vector<int>(b, 0));
    char skip;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf(" %c", &D[i][j]);
        }
    }

    int counter = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) if (D[i][j] == '#' && visited[i][j] == 0) {
            
            counter += DFS(i, j);

        }
    }

    printf("%d\n", counter);

    return 0;
}