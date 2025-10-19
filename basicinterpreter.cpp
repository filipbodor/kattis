#include <bits/stdc++.h>
using namespace std;

vector<int> labels;
unordered_map<int, string> commands;

int main() {

    string l;
    while (true) {
        getline(cin, l);
        
        if (l.empty()) break;

        int i = 0;
        int num = 0;
        while (l[i] != ' ') {
            num = num * 10 + (l[i] - '0');
            i++;
        }

        labels.push_back(num);
        commands[num] = string(l.begin() + i + 1, l.end());

    }

    sort(labels.begin(), labels.end());

    int i = 0;
    int size = labels.size();
    while (i != size) {
        if (commands[labels[i]][0] == 'L') {

        }


        i++;
    }

    for (int i = 0; i < size; i++) {
        cout << labels[i] << ' ' << commands[labels[i]] << endl;
    }

    return 0;
}