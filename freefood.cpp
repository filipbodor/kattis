#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int days[365];
    for (int i = 0; i < 365; i++) days[i] = 0;

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;

        for (int i = a - 1; i < b; i++) {
            days[i] = 1;
        }
    }
    int cou = 0;
    for (int i = 0; i < 365; i++) if (days[i]) cou += 1;

    cout << cou << endl;

    return 0;
}