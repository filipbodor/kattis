#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pos {{2, 2}, {2, 4}, {4, 2}};

int main() {

    int c, d, e;

    for (auto &[a, b] : pos) {
        

        cout << "? " << a << " " << b << endl;
        cout.flush();
        cin >> c;

        if (c == 1) {
            cout << "? " << a-1 << " " << b << endl;
            cout.flush();
            cin >> c;

            cout << "? " << a << " " << b - 1 << endl;
            cout.flush();

            cin >> e;

            if (c == 1 && e == 1) {
                cout << "! " << a-1 << ' ' << b-1 << endl;
            } else if(c == 1) {
                cout << "! " << a-1 << ' ' << b << endl;
            } else if(e == 1) {
                cout << "! " << a << ' ' << b-1 << endl;
            } else  {
                cout << "! " << a << ' ' << b << endl;
            }

            return 0;
        }
    }

    int a = 4, b = 4;

    cout << "? " << a-1 << " " << b << endl;
    cout.flush();
    cin >> c;

    cout << "? " << a << " " << b - 1 << endl;
    cout.flush();

    cin >> e;

    if (c == 1 && e == 1) {
        cout << "! " << a-1 << ' ' << b-1 << endl;
    } else if(c == 1) {
        cout << "! " << a-1 << ' ' << b << endl;
    } else if(e == 1) {
        cout << "! " << a << ' ' << b-1 << endl;
    } else  {
        cout << "! " << a << ' ' << b << endl;
    }

    return 0;
}