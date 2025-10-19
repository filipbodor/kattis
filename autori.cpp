#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin >> a;

    if (a.size() != 0) cout << a[0];
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '-') {
            cout << a[i+1];
            i++;
        }
    }


    return 0;
}