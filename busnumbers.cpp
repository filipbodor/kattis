#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    priority_queue<int, vector<int>, greater<int>> pq;


    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        pq.push(a);
    }

    int low = pq.top(); pq.pop();
    int last = low;
    int cur = last;

    while (!pq.empty()) {
        cur = pq.top(); pq.pop();

        if (cur - 1 == last) {
            last = cur;
        } else {
            if (low == last) printf("%d ", low);
            else if (low + 1 == last) printf("%d %d ", low, last);
            else printf("%d-%d ", low, last);
            low = cur;
            last = cur;
        }
    }

    if (cur == low) {
        printf("%d\n", cur);
    } else {
        if (low + 1 == cur) printf("%d %d ", low, last);
        else printf("%d-%d ", low, cur);
    }

    return 0;
}