#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;

int squashes(int a, int b) {
    if (grid[a][b] == '#' || grid[a+1][b] == '#' || grid[a][b+1] == '#' || grid[a+1][b+1] == '#') return -1;

    int counter = 0;
    if (grid[a][b] == 'X') counter++;
    if (grid[a+1][b] == 'X') counter++;
    if (grid[a][b+1] == 'X') counter++;
    if (grid[a+1][b+1] == 'X') counter++;

    return counter;
}


int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    grid.assign(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }
    
    unordered_map<int, int> counter {{-1, 0}, {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}};

    for (int i = 0; i < R - 1; i++) {
        for (int j = 0; j < C - 1; j++) if (grid[i][j] != '#') {
            counter[squashes(i, j)]++;
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", counter[i]);
    }

    return 0;
}