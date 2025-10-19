#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);


    vector<vector<char>> p(8, vector<char>(8, '.'));
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) p[i][j] = ((i + j) % 2 == 1) ? '.' : ':'; 

    for (int i = 7; i < (int)a.size() ;) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            p[a[i+1] - 'a'][a[i+2] - '1'] = a[i];
            i += 4;
        } else {
            p[a[i] - 'a'][a[i+1] - '1'] = 'P';
            i += 3;
        }
    }

    for (int i = 7; i < (int)b.size();) {
        if (b[i] >= 'A' && b[i] <= 'Z') {
            p[b[i+1] - 'a'][b[i+2] - '1'] = b[i] - ('A' - 'a');
            i += 4;
        } else {
            p[b[i] - 'a'][b[i+1] - '1'] = 'p';
            i += 3;
        }
    }

    printf("+---+---+---+---+---+---+---+---+\n");
    for (int i = 7; i >= 0; i--) {
        if (i % 2 == 1) printf("|.");
        else printf("|:");
        for (int j = 0; j < 8; j++) {
            printf("%c", p[j][i]);
            if ((i + j) % 2 == 1 && j != 7) printf(".|:");
            else if ((i + j) % 2 == 0 && j != 7) printf(":|.");
            else if ((i + j) % 2 == 1) printf(".|");
            else if ((i + j) % 2 == 0) printf(":|");
        }
        printf("\n+---+---+---+---+---+---+---+---+\n");
    }


    return 0;
}