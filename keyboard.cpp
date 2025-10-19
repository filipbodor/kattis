#include <bits/stdc++.h>
using namespace std;

int dist[51][51][10001];
int AM[55][55];
vector<vector<char>> mat;
int n, m;
string strr;
int sz;

vector<pair<int, int>> axes {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int BFS(int i, int j) {
    unordered_map<int, unordered_map<int, int>> visited; 
    queue<tuple<int, int, int, int>> qu;
    qu.push({0, 0, i, j});

    while (!qu.empty()) {
        auto [a, b, x, y] = qu.front(); qu.pop();

        if (AM[x][y] >= b) continue;

        while (b < sz && mat[x][y] == strr[b]) dist[x][y][b++] = a++;
        if (b == sz) return a;

        AM[x][y] = b;

        for (auto &[p, q] : axes) {
            int ap = x + p, aq = y + q;
            while ((ap >= 0 && ap < n && aq >= 0 && aq < m) && mat[ap][aq] == mat[x][y]) ap += p, aq += q;

            if (ap >= 0 && ap < n && aq >= 0 && aq < m) {
                if (AM[ap][aq] < b && (dist[ap][aq][b] == -1 || dist[ap][aq][b] > a + 1)) {
                    dist[ap][aq][b] = a + 1;
                    qu.push({a + 1, b, ap, aq});
                }
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d", &n, &m);

    mat.assign(n, vector<char>(m));
    vector<char> uniq {};
    unordered_set<char> chars;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &mat[i][j]);
            if (chars.count(mat[i][j]) == 0) {
                uniq.push_back(mat[i][j]);
                chars.insert(mat[i][j]);
            }
        }
    }

    char str[10005];
    scanf(" %s", &str);
    strr = str;
    strr += '*';
    sz = strr.size();

    memset(AM, -1, sizeof(AM));
    memset(dist, -1, sizeof(dist));

    int counter = BFS(0, 0);

    printf("%d\n", counter);

    return 0;
}