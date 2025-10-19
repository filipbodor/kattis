#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    getline(cin, a);

    int n = 0;
    for (int i = 0; i < (int)a.size() && a[i] <= '9' && a[i] >= '0'; i++) {
        n = n * 10 + (a[i] - '0');
    }

    vector<vector<string>> po(n, vector<string>());

    for (int i = 0; i < n; i++) {   
        getline(cin, a);

        string temp = "";

        for (int j = 0; j < a.size() && a[j] != '\n'; j++) {
            if (a[j] == ',') {
                po[i].push_back(temp);
                temp = "";
                j++;
            } else {
                temp += a[j];
            }
        }
        if (temp != "") po[i].push_back(temp);
    }

    vector<vector<int>> cha(n, vector<int>(n, 0));
    int size = po[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = 0; k < size; k++) {
                cha[i][j] += (po[i][k] != po[j][k]);
                cha[j][i] += (po[i][k] != po[j][k]);
            }
        }
    }

    vector<int> mima(n, -1);
    int mi = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mima[i] = max(mima[i], cha[i][j]);
        }
        mi = min(mi, mima[i]);
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%d ", cha[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("%d\n", mi);

    for (int i = 0; i < n; i++) {
        if (mi == mima[i]) {
            for (int j = 0; j < size; j++) {
                printf("%s", po[i][j].c_str());
                if (j != size - 1) printf(", ");
            }
            printf("\n");
        }
    }




    return 0;
}