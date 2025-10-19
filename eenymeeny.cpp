#include <bits/stdc++.h>
using namespace std;

void move(int a, int n, vector<string> &b) {
    for (int i = a; i < n; i++) {
        b[i] = b[i + 1];
    }
}


int main() {
    char a;
    int ca = 1;

    while (scanf("%c", &a) == 1 && a != '\n') {
        if (a == ' ') ca++;
    }

    vector<string> names {};

    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        char name[105];
        scanf("%s", &name);
        names.push_back(name);
    }

    int start = 0;
    vector<vector<string>> teams(2, vector<string>());
    int t = 0;

    for (int i = 0; i < n; i++) {
        //printf("%d, %d\n", start, (n - i));
        start = (start + ca - 1) % (n - i);
        teams[t].push_back(names[start]);
        t = 1 - t;
        move(start, n - 1, names);
        if (i != n - 1) start %= (n - i - 1);
    }

    printf("%d\n", (int)teams[0].size());
    for (string s : teams[0]) {
        printf("%s\n", s.c_str());
    }
    printf("%d\n", (int)teams[1].size());
    for (string s : teams[1]) {
        printf("%s\n", s.c_str());
    }

    return 0;
}