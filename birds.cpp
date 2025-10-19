#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, d, n;

    scanf("%d %d %d", &l, &d, &n);

    priority_queue<int, vector<int>, greater<int>> birds; 
    birds.push(6 - d);
    birds.push(l - 6 + d);

    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        birds.push(a);
    }

    int ad = 0;
    while (1) {
        int a = birds.top(); birds.pop();
        if (birds.empty()) break;
        int b = birds.top();

        ad += (b - a - d) / d;
    }

    printf("%d\n", ad);

    return 0;
}