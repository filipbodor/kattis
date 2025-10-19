#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string a;
        cin >> a;

        int n = sqrt(a.size());

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                cout << a[j * n + i];
            }
        }
        cout << endl;
    }

    return 0;
}