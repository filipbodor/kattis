#include <bits/stdc++.h>
using namespace std;

int N, t;
vector<long long> a;


void e1() {
    unordered_map<long long, int> vis;

    for (int i = 0; i < N; i++) {
        if (vis.count(7777 - a[i]) != 0 && vis[i] != i) {
            printf("Yes\n");
            return;
        }
        vis[a[i]] = i;
    }

    printf("No\n");
}

void e2() {
    unordered_set<long long> vis;

    for (int i = 0; i < N; i++) {
        if (vis.find(a[i]) != vis.end()) {
            printf("Contains duplicate\n");
            return;
        }
        vis.insert(a[i]);
    }
    printf("Unique\n");
}

void e3() {
    unordered_map<long long, int> vis;
    for (int i = 0; i < N; i++) {
        vis[a[i]]++;
        if (vis[a[i]] > N / 2) {
            printf("%d\n", a[i]);
            return;
        }
    }
    printf("-1\n");
}

void e4() {
    sort(a.begin(), a.end());

    if (N % 2 == 0) {
        printf("%d %d\n", a[N / 2 - 1], a[N / 2]);
    } else {
        printf("%d\n", a[N / 2]);
    }
}

void e5() {
    sort(a.begin(), a.end());
    for (int i = 0; i < N && a[i] <= 999; i++) {
        if (a[i] >= 100) {
            printf("%d ", a[i]);
        }
    }
}

int main() {
    scanf("%d %d", &N, &t);

    a.assign(N, 0);

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    if (t == 1) {
        e1();
    } else if (t == 2) {
        e2();
    } else if (t == 3) {
        e3();
    } else if (t == 4) {
        e4();
    } else if (t == 5) {
        e5();
    }


    return 0;
}