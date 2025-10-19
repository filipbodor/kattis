#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> axes {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(vector<vector<int>> &start) {
    
    map<vector<vector<int>>, int> dist;

    queue<vector<vector<int>>> q;
    q.push(vector<vector<int>>(3, vector<int>(3, 0)));
    dist[vector<vector<int>>(3, vector<int>(3, 0))] = 0;

    if (q.front() == start) return 0;

    while (!q.empty()) {
        auto a = q.front(); q.pop();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<vector<int>> newState = a;

                newState[i][j] = !newState[i][j];
                for (auto &[p, o] : axes) {
                    int ap = i + p, ao = j + o;
                    if (ap >= 0 && ap < 3 && ao >= 0 && ao < 3) {
                        newState[ap][ao] = !newState[ap][ao];
                    }
                }
                if (newState == start) return dist[a] + 1;

                auto d = dist.find(newState);
                if (d == dist.end() || ((*d).second > dist[a] + 1)) {
                    q.push(newState);
                    dist[newState] = dist[a] + 1;
                }
            }
        }
    }
    return 1e9;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        vector<vector<int>> start(3, vector<int>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char a;
                scanf(" %c", &a);
                start[i][j] = (a == '*');
            }
        }


        int ans = bfs(start);
        printf("%d\n", ans);

    }

    return 0;
}