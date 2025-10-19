#include <bits/stdc++.h>
using namespace std;

vector<int> un(vector<int> &a) {
    vector<int> bits1(8, 0);
    vector<int> bits2(8, 0);

    for (int i = 7; i >= 0; i--) {
        if (a[i]) bits1[i] = !bits2[i];
        else bits1[i] = bits2[i];
        if (i != 0) bits2[i-1] = bits1[i];
    }
    return bits1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        vector<int> bits(8, 0);

        for (int j = 7; j >= 0 && a != 0; j--) {
            bits[j] = a % 2;
            a /= 2;
        }

        auto b = un(bits);

        int counter = 0;
        for (int j = 7; j >= 0; j--) {
            counter += b[7 - j] * pow(2, j);
        }


        printf("%d ", counter);
    }

    return 0;
}