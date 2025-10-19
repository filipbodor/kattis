#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> AL;
vector<string> res;
unordered_set<string> visited;

void dfs_traversal(string s) {
    visited.insert(s);

    for (auto &o : AL[s]) if (visited.find(o) == visited.end()) {
        dfs_traversal(o);
    }
    res.push_back(s);
}

int main() {
    string a;
    getline(cin, a);

    int n = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] >= '0' && a[i] <= '9') n = n * 10 + (a[i] - '0');
        else break;
    }


    for (int i = 0; i < n; i++) {
        getline(cin, a);

        string b = ""; 
        int j = 0;
        for (j; a[j] != ':'; j++) {
            b += a[j];
        }

        j++;
        string c = "";
        for (j; j < (int)a.size() && a[j] != '\n'; j++) {
            if (a[j] == ' ') {
                if (!c.empty())  AL[c].emplace_back(b);
                c = "";
            } else {
                c += a[j];
            }
        }
        if (!c.empty()) AL[c].emplace_back(b);
    }


    getline(cin, a);
    string d = "";
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != '\n') d += a[i];
        else break;
    }

    dfs_traversal(d);

    for (int j = res.size() - 1; j >= 0; j--) {
        printf("%s\n", res[j].c_str());
    }

    return 0;
}