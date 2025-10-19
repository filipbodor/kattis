#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> lines {  {"xxxxx", "....x", "xxxxx", "xxxxx", "x...x", "xxxxx", "xxxxx", "xxxxx", "xxxxx", "xxxxx"},
                                {"x...x", "....x", "....x", "....x", "x...x", "x....", "x....", "....x", "x...x", "x...x"},
                                {"x...x", "....x", "....x", "....x", "x...x", "x....", "x....", "....x", "x...x", "x...x"},
                                {"x...x", "....x", "xxxxx", "xxxxx", "xxxxx", "xxxxx", "xxxxx", "....x", "xxxxx", "xxxxx"},
                                {"x...x", "....x", "x....", "....x", "....x", "....x", "x...x", "....x", "x...x", "....x"},
                                {"x...x", "....x", "x....", "....x", "....x", "....x", "x...x", "....x", "x...x", "....x"},
                                {"xxxxx", "....x", "xxxxx", "xxxxx", "....x", "xxxxx", "xxxxx", "....x", "xxxxx", "xxxxx"}};


int findInt(vector<string>& input, int i) {
    for (int l = 0; l < 10; l++) {
        bool flag = true;
        for (int k = 0; k < 7 && flag; k++) {
            bool flag2 = true;
            for (int j = 0; j < 5 && flag2; j++) {
                if (input[k][i * 6 + j] != lines[k][l][j]) flag2 = false;
            }
            if (!flag2) flag = false;
        }
        if (flag) return l;
    }
    return -1;
}

int main() {
    vector<string> input(7);

    for (int i = 0; i < 7; i++) {
        cin >> input[i];
    }

    int size = input[0].size() / 6 + 1;

    bool plus = false;
    int first = 0;
    int second = 0;

    for (int i = 0; i < size; i++) {
        int a = findInt(input, i);

        if (a == -1) {
            plus = true;
            continue;
        }

        if (!plus) {
            first = first * 10 + a;
        } else {
            second = second * 10 + a;
        }
    }

    int ans = first + second;
    vector<int> digits {};
    
    while (ans != 0) {
        digits.push_back(ans % 10);
        ans /= 10;
    }

    for (int j = 0; j < 7; j++) {
        for(int i = digits.size() - 1; i >= 0; i--) {
            cout << lines[j][digits[i]];
            if (i != 0) cout << ".";
        }
        cout << endl;
    }

    return 0;
}