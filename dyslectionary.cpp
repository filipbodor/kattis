#include <bits/stdc++.h>
using namespace std;

int main() {
    string b, c;
    char d;

    bool first = true;

    while ((scanf("%c", &d) != EOF)) {

        if (!first) printf("\n");
        else first = false;


        vector<string> ws {};
        vector<string> wsr {};
        unordered_map<string, string> wsrt {};

        int masize = 0;
        do {
            string a = "";
            do {
                a += d;
            } while (scanf("%c", &d) != EOF && d != '\n');

            b = a;
            reverse(b.begin(), b.end());
            ws.push_back(a);
            wsr.push_back(b);
            wsrt[b] = a;
            masize = max(masize, (int)a.size());
        } while (scanf("%c", &d) != EOF && d != '\n');

        sort(wsr.begin(), wsr.end());

        for (string s : wsr) {
            for (int i = 0; i < masize - (int)s.size(); i++) printf(" ");
            printf("%s\n", wsrt[s].c_str());
        }
    }

    return 0;
}