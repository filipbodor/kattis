#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> AL;
vi counter;

ii furthest(vector<vi> &AL, int start, vi &visited) {
    map<int, int> dist;

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int furDist = 0;
    int furIdx = start;

    while (!q.empty()) {
        int k = q.front(); q.pop();
        visited[k] = 1;
        for (auto x : AL[k]) if (dist.count(x) == 0) {
            dist[x] = dist[k] + 1;
            q.push(x);
            if (dist[x] > furDist) {
                furDist = dist[x];
                furIdx = x;
            }
        }
    }

    return {furIdx, furDist};
}

int main() {
    int c, l;
    scanf("%d %d", &c, &l);
    
    AL.assign(c, vi());
    counter.assign(c, 0);

    for (int i = 0; i < l; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        AL[a].emplace_back(b);
        AL[b].emplace_back(a);
        counter[a]++;
        counter[b]++;
    }

    vi diameters {};
    vi visited(c, -1);
    for (int i = 0; i < c; i++) if (visited[i] == -1) {
        ii res1 = furthest(AL, i, visited);
        ii res2 = furthest(AL, res1.first, visited);

        diameters.emplace_back(res2.second);
    }
    
    sort(diameters.begin(), diameters.end());
    while (diameters.size() > 1) {
        int w1 = diameters.back() / 2;
        int w2 = diameters.back() / 2;
        if(diameters.back() % 2 == 1) w1++;
        diameters.pop_back();

        int w3 = diameters.back() / 2;
        int w4 = diameters.back() / 2;
        if(diameters.back() % 2 == 1) w3++;
        diameters.pop_back();

        diameters.emplace_back(max({w1 + w2, w3 + w4, w1 + w3 + 1}));

    }

    printf("%d\n", diameters[0]);

    // for (int i = 0; i < c; i++) {
    //     printf("\n%d: ", i);
    //     for (int j = 0; j < (int)AL[i].size(); j++) {
    //         printf("%d ", AL[i][j]);
    //     }
    // }x

    return 0;
}