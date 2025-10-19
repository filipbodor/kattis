#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> visited;
unordered_map<string, vector<string>> AL;
int n;

vector<string> res;

int dfs(string name, int depth) {
    if (depth == n) return 1;
    visited[name] = 1;

    for (string s : AL[name]) if (visited[s] == -1) {
        int a = dfs(s, depth + 1);
        if (a) {
            res[depth] = s;
            return 1;
        }
    }

    visited[name] = 0;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        vector<string> names(n);
        AL.clear();

        for (int i = 0; i < n; i++) {
            cin >> names[i];
        }

        sort(names.begin(), names.end());



        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (names[i][(int)names[i].size() - 1] == names[j][0]) {
                    AL[names[i]].emplace_back(names[j]);
                }
                if (names[j][(int)names[j].size() - 1] == names[i][0]) {
                    AL[names[j]].emplace_back(names[i]);
                }
            }
        }

        visited.clear();
        for (string s : names) {
            sort(AL[s].begin(), AL[s].end());
            visited[s] = -1;
        }

        
        unordered_map<string, int> idx;
        vector<string> st, ans;
        unordered_map<string, int> is_there;
        bool flag;

        for (string s : names) {
            for (string s1 : names) idx[s1] = 0;
            st.clear();
            ans.clear();
            for (string s1 : names) is_there[s1] = 0;
            
            st.push_back(s);
            while (!st.empty()) {
                string u = st.back();
                if (idx[u] < (int)AL[u].size()) {
                    st.push_back(AL[u][idx[u]]);
                    ++idx[u];
                } else {
                    ans.push_back(u);
                    st.pop_back();
                    is_there[u] = 1;
                }
            }
            flag = true;
            for (int i = 0; i < n && flag; i++) flag = is_there[names[i]];
            if (flag) break;
        }

        reverse(ans.begin(), ans.end());

        if (flag) {

            for (int i = 0; i < n - 1; i++) {
                cout << ans[i] << '.';
            } cout << ans[n-1] << endl;
        } else {
            cout << "***" << endl;
        }

        


    }

    return 0;
}