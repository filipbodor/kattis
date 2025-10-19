#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> wrs;
vector<char> chars;
vector<int> exc;
unordered_map<char, int> idxs;
vector<long long> sums(10);
vector<int> mult;

bool evaluate(vector<int> &numbers) {
    long long num = 0;
    for (int j = 0; j < (int)wrs[wrs.size() - 1].size(); j++) {
        num = num * 10 + numbers[idxs[wrs[wrs.size() - 1][j]]];
    }
    long long su = 0;
    for (int i = 0; i < m; i++) {
        su += mult[i] * numbers[i];
    }
    return (num == su);
}

int cnt = 0;
void backtracking(int type, int mask, vector<int> &numbers) {
    if (type == m) { cnt += evaluate(numbers); return; }

    int free = ((1 << 10) - 1) & (~mask);

    while (free) {
        //printf("%d\n", free);
        int f = free & -free;
        int ctz = __builtin_ctz(f);
        free -= f;
        
        if (exc[type] == 1 && ctz == 0) continue;
        numbers[type] = ctz;  
        backtracking(type + 1, mask|f, numbers);
    }
}

int main() {
    scanf("%d", &n);

    wrs.assign(n, "");

    for (int i = 0; i < n; i++) {
        char a[15];
        scanf("%s", a);
        wrs[i] = a;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)wrs[i].size(); j++) {
            if (idxs.find(wrs[i][j]) == idxs.end()) {
                chars.push_back(wrs[i][j]);
                idxs[wrs[i][j]] = chars.size() - 1;
            }
        }
    }

    m = chars.size();
    exc.assign(m, 0);
    for (int i = 0; i < n; i++) {
        exc[idxs[wrs[i][0]]] = 1;
    }

    mult.assign(m, 0);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < (int)wrs[i].size(); j++) {
            mult[idxs[wrs[i][j]]] += pow(10, (int)wrs[i].size() - j - 1);
        }
    }

    vector<int> numbers(m, 0);
    backtracking(0, 0, numbers);

    printf("%d\n", cnt);


    

    return 0;
}