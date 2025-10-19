#include <bits/stdc++.h>
using namespace std;

vector<string> names;
unordered_map<string, string> speak;
unordered_map<string, vector<string>> understand;

unordered_map<string, vector<string>> AL;
unordered_map<string, vector<string>> AL_T;
unordered_map<string, int> visited;
vector<string> S;

int Kosaraju(string name, int pass) {
    visited[name] = 1;
    vector<string> &neighbor = (pass == 1) ? AL[name] : AL_T[name];
    int counter = 1;

    for (string n : neighbor) {
        if (visited[n] == 0) {
            counter += Kosaraju(n, pass);
        }
    }
    S.push_back(name);
    return counter;
}


int main() {
    string a;
    int T = 0;
    getline(cin, a);
    for (int i = 0; i < (int)a.size() && a[i] <= '9' && a[i] >= '0'; i++) {
        T = T * 10 + (a[i] - '0');
    }


    int n = 0;
    while (T-- && getline(cin, a)) {
        string b = "", c = "", temp = "";
        vector<string> d = {};

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '\n') break;

            if (a[i] == ' ') {
                if (b == "") b = temp;
                else if (c == "") c = temp;
                else d.emplace_back(temp);
                temp = "";
            } else {
                temp += a[i];
            }
        }
        if (c == "") c = temp;
        else d.emplace_back(temp);

        if (n != 0 && names[0] == b) break;

        speak[b] = c;
        understand[b] = d;
        understand[b].emplace_back(c);
        names.emplace_back(b);
        AL[b] = {};
        AL_T[b] = {};

        n++;
    }

    for (string s1 : names) {
        for (string s2 : understand[s1]) {
            for (string s3 : names) if (s1 != s3) {
                if (s2 == speak[s3]) {
                    AL[s3].emplace_back(s1);
                    AL_T[s1].emplace_back(s3);
                }
            }
        }
    }

    // for (string name : names) {
    //     cout << name << ": ";
    //     for (string s : AL[name]) {
    //         cout << s << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;


    S.clear();
    for (string s : names) visited[s] = 0;

    for (string s : names) {
        if (visited[s] == 0) {
            Kosaraju(s, 1);
        }
    }
    for (string s : names) visited[s] = 0;
    int ma = 0;
    for (int i = S.size()-1; i >= 0; i--) {
        if (visited[S[i]] == 0) {
            int a = Kosaraju(S[i], 2);
            ma = max(ma, a);
        }
    }
    int res = n - ma;
    printf("%d\n", res);

    return 0;
}