#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<bool> alp(n);
    for (int i = 0; i < n; i++) {
        char l;
        scanf("  %c", &l);
        alp[i] = (l == 'T');
    }


    stack<bool> q;

    char a;
    while (scanf("  %c", &a) != EOF) {
        if (a >= 'A' && a <= 'Z') {
            q.push(alp[a - 'A']);
        } else if (a == '*') {
            bool c = q.top(); q.pop();
            bool d = q.top(); q.pop();
            q.push(c & d);
        } else if (a == '+') {
            bool c = q.top(); q.pop();
            bool d = q.top(); q.pop();
            q.push(c | d);
        } else if (a == '-') {
            bool c = q.top(); q.pop();
            q.push(!c);
        }
    }

    if (q.top()) printf("T\n");
    else printf("F\n");

    return 0;
}