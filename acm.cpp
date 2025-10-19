#include <bits/stdc++.h>
using namespace std;

int main() {


    int a;
    char b;
    string c;

    int solved[26];
    int minutes[26];

    for (int i = 0; i < 26; i++) {
        solved[i] = 0;
        minutes[i] = 0;
    }

    while (1) {
        cin >> a;
        if (a == -1) break;

        cin >> b >> c;

        if (c == "right") {
            solved[b - 'A'] = 1;
            minutes[b - 'A'] += a;
        } else {
            if (!solved[b - 'A']) {
                minutes[b - 'A'] += 20;
            }
        }
    }

    int m = 0, n = 0;
    for (int i = 0; i < 26; i++) {
        if (solved[i]) {
            n++;
            m += minutes[i];
        }
    }

    cout << n << ' ' << m << endl;


    return 0;
}