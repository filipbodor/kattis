#include <bits/stdc++.h>
using namespace std;

vector<int> m = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLegal(int a, int b, int c) {
    if (b <= 12 && b >= 1) {
        if (2000 <= c && c < 3000) {
            return (a > 0 && a <= m[b] + ((b == 2) && c % 4 == 0 && (c % 400 == 0 || c % 100 != 0)));
        }
    }

    return false;
}

int main() {
    int d[3];
    string str = "";
    char k;
    int idx = 0, o = 0;

    while (scanf(" %c", &k) == 1) {
        if (k == '/') {
            d[idx] = o;
            o = 0;
            idx++;
        } else {
            o = o * 10 + (k - '0');
        }
        str += k;
    }
    d[2] = o;

    int a = d[0], b = d[1], c = d[2];

    vector<vector<int>> combs {};

    sort(d, d+3);
    
    do {
        if (isLegal(d[0], d[1], d[2] + (d[2] >= 2000 ? 0 : 2000))) {
            combs.push_back({d[2] + (d[2] >= 2000 ? 0 : 2000), d[1], d[0]});
        }

    } while (next_permutation(d, d+3));


    if (combs.empty()) {
        printf("%s is illegal\n", str.c_str()); 
    } else {
        sort(combs.begin(), combs.end());
        printf("%d-%0.2d-%0.2d\n", combs[0][0], combs[0][1], combs[0][2]);
    }

    return 0;
}