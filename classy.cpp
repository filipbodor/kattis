#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        unordered_map<string, vector<int>> vec; 
        vector<string> names {};

        for (int i = 0; i < n; i++) {
            char c;
            scanf(" %c", &c);
            string a = "", temp = "";
            vector<int> r {};

            do {
                if (c == ':') {
                    a = temp;
                    scanf("%c", &c);
                    temp = "";
                } else if (c == '-' || c == ' ') {
                    if (temp == "upper") {
                        r.push_back(1);
                    } else if (temp == "lower") {
                        r.push_back(-1);
                    } else if (temp == "middle") {
                        r.push_back(0);
                    }
                    temp = "";
                } else {
                    temp += c;
                }
            } while (scanf("%c", &c) == 1 && c != '\n');

            names.push_back(a);
            reverse(r.begin(), r.end());
            vec[a] = r;
        }


        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < vec[names[i]].size(); j++) {
        //         printf("%d ", vec[names[i]][j]);
        //     }
        //     printf("\n");
        // }

        sort(names.rbegin(), names.rend(), [&vec](const string &l, const string &r) {

            int i;
            for (i = 0; i < vec[l].size() && i < vec[r].size(); i++) {
                if (vec[l][i] > vec[r][i]) return false;
                else if (vec[l][i] < vec[r][i]) return true;
            }

            if (i < vec[l].size()) {
                while (i < vec[l].size() && vec[l][i] == 0) i++;
                if (!(i < vec[l].size())) return l > r;
                return (vec[l][i] != 1);
            } else if (i < vec[r].size()) {
                while (i < vec[r].size() && vec[r][i] == 0) i++;
                if (!(i < vec[r].size())) return l > r;
                return (vec[r][i] != -1);
            }

            return l > r;
        });

        for (int i = 0; i < names.size(); i++) {
            printf("%s\n", names[i].c_str());
        }
        printf("==============================\n");
    }

    return 0;
}