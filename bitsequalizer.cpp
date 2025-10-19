#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;

    for (int o = 1; o <= T; o++) {
        string a, b;
        int changes = 0;
        cin >> a >> b;
        int size = a.size();
        vector<int> av (size, -1);
        vector<int> bv (size, -1);

        int a0 = 0, a1 = 0, b0 = 0, b1 = 0, ex = 0;
        for (int i = 0; i < size; i++) {
            if (a[i] == '0') a0++;
            else if (a[i] == '1') a1++;
            else ex++;
            if (b[i] == '0') b0++;
            else b1++;
            
            if (a[i] == '0') av[i] = 0;
            else if (a[i] == '1') av[i] = 1;
            if (b[i] == '0') bv[i] = 0;
            else if (b[i] == '1') bv[i] = 1;
        }

        int ch0 = b0 - a0, ch1 = b1 - a1;

        if (ch0 > ex) {
            printf("Case %d: -1\n", o);
            continue;
        }

        for (int i = 0; i < size && ch0 > 0; i++) {
            if (av[i] == -1 && bv[i] == 0) {
                changes++;
                av[i] = 0;
                ch0--;
                ex--;
            } 
        }

        if (ch0 > 0) {
            for (int i = 0; i < size && ch0 > 0; i++) {
                if (av[i] == -1) {
                    changes++;
                    av[i] = 0;
                    ch0--;
                    ex--;
                } 
            }
        }
        for (int i = 0; i < size && ex > 0; i++) {
            if (av[i] == -1) {
                changes++;
                av[i] = 1;
                ch1--;
                ex--;
            } 
        }

        if (ch0 != 0 && ch1 != 0) {
            for (int i = 0; i < size && ch1 > 0; i++) {
                if (av[i] == 0 && bv[i] == 1) {
                    changes++;
                    av[i] = 1;
                    ch1--; ch0++;
                } 
            }
        }

        int c = 0;
        for (int i = 0; i < size; i++) {
            if (av[i] != bv[i]) c++;
        }

        changes += c / 2;

        printf("Case %d: %d\n", o, changes);
    }

    return 0;
}