#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;

        if (c == -1) continue;

        a += c;
        b++;
    }

    cout << setprecision(10) << (double)a / double(b) << endl;
    return 0;
}