#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin >> a;

    int size = a.size();
    
    for (int i = 0; i < size; i++) {
        if (i < size - 2 && a[i] != a[i+1] && a[i+1] != a[i+2] && a[i] != a[i+2]) {
            cout << 'C';
            i += 2;
        } else if (a[i] == 'R') {
            cout << 'S';
        } else if (a[i] == 'B') {
            cout << 'K';
        } else if (a[i] == 'L') {
            cout << 'H';
        }
    }

    cout << endl;

    return 0;
}