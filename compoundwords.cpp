#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<string> ws; 
    vector<string> end; 
    unordered_set<string> wu; 

    char w[12];
    while (scanf("%s", &w) != EOF) {
        ws.push_back(w);
    }

    sort(ws.begin(), ws.end());

    int size = ws.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) if (i != j) {
            string to = ws[i] + ws[j];

            if (wu.count(to) == 0) {
                end.push_back(to);
                wu.insert(to);
            }
        }
    }

    sort(end.begin(), end.end());
    for (string i : end) {
        printf("%s\n", i.c_str());
    }

    return 0;
}