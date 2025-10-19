#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);
    
    char a;
    stack<char> st; 
    for (int i = 0; i < n; i++) {
        scanf("%c", &a);

        if (a == '(' || a == '[' || a == '{') {
            st.push(a);
        } else if (a == ')') {
            if (st.empty()) {
                printf("%c %d\n", a, i);
                return 0;
            }
            char b = st.top(); st.pop();
            if (b != '(') {
                printf("%c %d\n", a, i);
                return 0;
            }
        } else if (a == ']') {
            if (st.empty()) {
                printf("%c %d\n", a, i);
                return 0;
            }
            char b = st.top(); st.pop();
            if (b != '[') {
                printf("%c %d\n", a, i);
                return 0;
            }
        } else if (a == '}') {
            if (st.empty()) {
                printf("%c %d\n", a, i);
                return 0;
            }
            char b = st.top(); st.pop();
            if (b != '{') {
                printf("%c %d\n", a, i);
                return 0;
            }
        }
    }

    printf("ok so far\n");

    return 0;
}