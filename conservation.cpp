#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<int> lab;
vector<int> visited;
vector<int> co;

int bfs(queue<int> s, int l, queue<int> sc = {}) {

    while (!s.empty()) {
        int a = s.front(); s.pop();

        visited[a] = 1;
        
        for (int i : AL[a]) {
            if (visited[i] == -1) {
                co[i]--;
                if (co[i] == 0 && lab[i] == l) {
                    s.push(i);
                } else if (co[i] == 0) {
                    sc.push(i);
                }
            }
        }
    }

    if (!sc.empty()) return 1 + bfs(sc, 3 - l);
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        lab.assign(n+1, 1);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &lab[i]);
        }

        AL.assign(n+1, {});
        vector<int> com(n+1, 0);

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            AL[a].push_back(b);
            com[b]++;
        }

        queue<int> s1 {};
        queue<int> s2 {};

        for (int i = 1; i <= n; i++) {
            if (com[i] == 0) {
                if (lab[i] == 1) s1.push(i);
                else if (lab[i] == 2) s2.push(i);
            }
        }


        co = com;
        visited.assign(n+1, -1);
        int a = bfs(s1, 1, s2);


        co = com;
        visited.assign(n+1, -1);
        int b = bfs(s2, 2, s1);

        int mi = min(a, b);

        printf("%d\n", mi);

    }

    return 0;
}