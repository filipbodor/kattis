#include <bits/stdc++.h>
using namespace std;

void move(vector<int> &m, int n) {
    int size = m.size();
    int actual_n = n % size;

    vector<int> m_c = m;
    for (int i = 0; i < size; i++) {
        m_c[i] = m[(i + actual_n) % size];
    }
    m = m_c;
}

int main() {
    int T;
    scanf("%d", &T);


    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> m = {};

        for (int i = n; i > 0; i--) {
            m.push_back(i);
            move(m, i);
        }

        for (int i = n - 1; i >= 0; i--) printf("%d ", m[i]);
        printf("\n");
    }

    return 0;
}