#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string new_s = "";
    
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] <= 'Z' && s[i] >= 'A') {
            //printf("%c", ((s[i] - 'A') + 13) % 26 + 'A');
            new_s += ((s[i] - 'A') + 13) % 26 + 'A';
        } else {
            //printf("%c", ((s[i] - 'a') + 13) % 26 + 'a');
            new_s += ((s[i] - 'a') + 13) % 26 + 'a';
        }
    }

    int c1 = 0, c2 = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (i % 3 == 0 && (s[i] != 'P' && s[i] != 'p')) c1++;
        else if (i % 3 == 1 && (s[i] != 'E' && s[i] != 'e')) c1++;
        else if (i % 3 == 2 && (s[i] != 'R' && s[i] != 'r')) c1++;
        
        if (i % 3 == 0 && (new_s[i] != 'P' && new_s[i] != 'p')) c2++;
        else if (i % 3 == 1 && (new_s[i] != 'E' && new_s[i] != 'e')) c2++;
        else if (i % 3 == 2 && (new_s[i] != 'R' && new_s[i] != 'r')) c2++;
    }

    printf("%d\n", min(c1, c2));


    return 0;
}