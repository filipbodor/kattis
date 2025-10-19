#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    stack<int> st;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (!st.empty() && st.top() % 2 == a % 2) st.pop();
        else st.push(a);
    }

    printf("%d\n", st.size());

    return 0;
}