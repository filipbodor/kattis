#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (b == "1") {
        cout << a << endl;
    } else if (b.size() > a.size()) {
        cout << "0.";
        for (int i = 1; i < (int)b.size() - (int)a.size(); i++) cout << '0';

        int idx = 0;
        while (a[(int)a.size() - 1 - idx] == '0') idx++;
        for (int i = 0; i < (int)a.size() - idx; i++) cout << a[i];
        cout << endl;
     } else {
        int idx = 0;
        while (a[(int)a.size() - 1 - idx] == '0' && idx < (int)b.size() - 1) idx++;
        for (int i = 0; i < (int)a.size() - idx; i++) {
            if ((int)a.size() - ((int)b.size() - 1) == i) cout << '.';
            cout << a[i];
        }
        cout << endl;
     }

    

    return 0;
}