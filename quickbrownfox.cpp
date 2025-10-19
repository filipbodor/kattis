#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        int let[26];
        for (int i = 0; i < 26; i++) let[i] = 0;

        string line;
        getline(cin, line);

        for (char c : line) {
            if (c >= 'a' && c <= 'z') let[c-'a'] = 1;
            else if (c >= 'A' && c <= 'Z') let[c-'A'] = 1;
        }

        string res = "";
        for (int i = 0; i < 26; i++) {
            if (let[i] == 0) res += (char)(i + 'a');
        }

        if (res != "") {
            cout << "missing " << res << endl;
        } else {
            cout << "pangram" << endl;
        }
    }

    return 0;
}