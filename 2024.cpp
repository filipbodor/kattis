#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }
    int d;
    cin >> d;

    
    if (d == 0) {
        for (int i = 0; i < 4; i++) {
            vector<int> line {};
            for (int j = 0; j < 4; j++) {
                if (a[i][j] != 0) {
                    int b = a[i][j];
                    while (j < 3 && a[i][j+1] == 0) j++;
                    
                    if (j < 3 && b == a[i][j+1]) {
                        line.push_back(b * 2);
                        j++;
                    } else {
                        line.push_back(b);
                    }
                }
            }
            for (int j = 0; j < 4; j++) {
                if (j < line.size()) a[i][j] = line[j];
                else a[i][j] = 0;
            }
        }
    }
    
    else if (d == 1) {
        for (int i = 0; i < 4; i++) {
            vector<int> line {};
            for (int j = 0; j < 4; j++) {
                if (a[j][i] != 0) {
                    int b = a[j][i];
                    while (j < 3 && a[j+1][i] == 0) j++;
                    
                    if (j < 3 && b == a[j+1][i]) {
                        line.push_back(b * 2);
                        j++;
                    } else {
                        line.push_back(b);
                    }
                }
            }
            for (int j = 0; j < 4; j++) {
                if (j < line.size()) a[j][i] = line[j];
                else a[j][i] = 0;
            }
        }
    }
    
    else if (d == 2) {
        for (int i = 0; i < 4; i++) {
            vector<int> line {};
            for (int j = 0; j < 4; j++) {
                if (a[i][3-j] != 0) {
                    int b = a[i][3-j];
                    while (j < 3 && a[i][3-j-1] == 0) j++;
                    
                    if (j < 3 && b == a[i][3-j-1]) {
                        line.push_back(b * 2);
                        j++;
                    } else {
                        line.push_back(b);
                    }
                }
            }
            for (int j = 0; j < 4; j++) {
                if (j < line.size()) a[i][3-j] = line[j];
                else a[i][3-j] = 0;
            }
        }
    }
    
    else if (d == 3) {
        for (int i = 0; i < 4; i++) {
            vector<int> line {};
            for (int j = 0; j < 4; j++) {
                if (a[3-j][i] != 0) {
                    int b = a[3-j][i];
                    while (j < 3 && a[3-j-1][i] == 0) j++;
                    
                    if (j < 3 && b == a[3-j-1][i]) {
                        line.push_back(b * 2);
                        j++;
                    } else {
                        line.push_back(b);
                    }
                }
            }
            for (int j = 0; j < 4; j++) {
                if (j < line.size()) a[3-j][i] = line[j];
                else a[3-j][i] = 0;
            }
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d", a[i][j]);
            if (j != 3) printf(" ");
            else printf("\n");
        }
    }
    
    return 0;
}