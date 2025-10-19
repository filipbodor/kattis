#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    while (cin >> n && n != 0) {
        vector<int> bits(32, -1);

        for (int k = 0; k < n; k++) {
            string com;
            int i, j;
            cin >> com;

            if (com == "SET") {
                cin >> i;
                bits[i] = 1;
            } else if (com == "CLEAR") {
                cin >> i;
                bits[i] = 0;
            } else if (com == "AND") {
                cin >> i >> j;
                if (bits[i] != -1 && bits[j] != -1) {
                    bits[i] &= bits[j];
                } else if (bits[j] == 0 || bits[i] == 0) {
                    bits[i] = 0;
                } else {
                    bits[i] = -1;
                }
            } else if (com == "OR") {
                cin >> i >> j;
                if (bits[i] != -1 && bits[j] != -1) {
                    bits[i] |= bits[j];
                } else if (bits[j] == 1 || bits[i] == 1) {
                    bits[i] = 1;
                } else {
                    bits[i] = -1;
                }
            }
        }

        for (int i = 31; i >= 0; i--) {
            cout << (char)(bits[i] == -1 ? '?' : bits[i] + '0');
        }
        cout << endl;
    }

    return 0;
}