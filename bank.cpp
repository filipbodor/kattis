#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<pair<int, int>> people;

int mem[50][10010];

int findMax(int curTime, int p) {
    if (curTime > T || p == N) return 0;

    int &ans = mem[curTime][p];
    if (ans != -1) return ans;

    if (curTime > people[p].first) return ans = findMax(curTime, p + 1);

    return ans = max(findMax(curTime, p + 1), 
                     people[p].second + findMax(curTime + 1, p + 1));
}

int main() {
    scanf("%d %d", &N, &T);

    people.assign(N, {0, 0});
    memset(mem, -1, sizeof(mem));

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        people[i] = {b, a};
    }

    sort(people.begin(), people.end());

    int ma = findMax(0, 0);

    printf("%d\n", ma);

    return 0;
}