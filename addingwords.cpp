#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    unordered_map<string, int> mem;
    set<string> en;

    string com;
    while (cin >> com) {
        if (com == "def") {
            string a;
            int b;
            cin >> a >> b;
            mem[a] = b;
            en.insert(a);
        } else if (com == "calc") {
            string a;
            char c;
            cin >> a >> c;
            cout << a << ' ' << c << ' ';
            int res = mem[a];
            int unk = 1;
            if (en.find(a) == en.end()) unk = 0;
            while (c != '=') {
                string d;
                cin >> d;
                if (en.find(d) == en.end()) unk = 0;
                if (c == '-') {
                    res -= mem[d];
                } else if (c == '+') {
                    res += mem[d];
                }
                cin >> c;
                cout << d << ' ' << c << ' ';
            }
            int flag = 1;
            if (unk == 1) {
                for (string e : en) {
                    if (mem[e] == res) {
                        cout << e << endl;
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) cout << "unknown" << endl;
        } else if (com == "clear") { 
            mem = {};
            en = {};
        }
    }


    return 0;
}