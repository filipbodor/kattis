#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    scanf("%d", &n);

    string line;
    getline(cin, line);

    vector<string> names {};
    unordered_set<string> namesIn;
    unordered_map<string, unordered_set<string>> cou;
    unordered_map<string, int> counting;
    unordered_set<string> wordsIn;
    vector<string> words;


    for (int i = 0; i < n; i++) {
        
        getline(cin, line);

        int ma = 0;
        string temp = "", name = "";
        for (int j = 0; j < (int)line.size() + 1; j++) {
            if (j >= (int)line.size() || line[j] == ' ') {
                if (name == "") {
                    name = temp;
                    if (namesIn.count(name) == 0) {
                        names.push_back(name);
                        namesIn.insert(name);
                    }

                } else {
                    if (wordsIn.count(temp) == 0) {
                        wordsIn.insert(temp);
                        words.push_back(temp);
                    }
                    cou[temp].insert(name);
                    counting[temp]++;
                }
                temp = "";
            } else {
                temp += line[j];
            }
        }
    }

    sort(words.begin(), words.end(), [&counting](const string &a, const string &b) {
        if (counting[a] > counting[b]) return true;
        else if (counting[a] < counting[b]) return false;
        return a < b;
    });

    int flag = 0;

    for (string w : words) {
        //cout << w << ": " << names.size() << ", " << cou[w].size() << endl;
        if (names.size() == cou[w].size()) {
            cout << w << endl;
            flag = 1;
        }
    }

    if (!flag) {
        cout << "ALL CLEAR" << endl;
    }



    return 0;
}