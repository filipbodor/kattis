#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<string> cos;
    unordered_map<string, int> counter;

    int ma = 0;

    for (int i = 0; i < n; i++) {

        char co[5];

        vector<string> courses(5);

        for (int j = 0; j < 5; j++) {
            scanf("%s", &co);
            courses[j] = co;
        }
        sort(courses.begin(), courses.end());
        string costr = courses[0] + courses[1] + courses[2] + courses[3] + courses[4];
        cos.push_back(costr);

        counter[costr]++;
        ma = max(ma, counter[costr]);
    }

    int c = 0;
    for (string co : cos) {
        if (counter[co] == ma) c++;
    }

    printf("%d\n", c);

    return 0;
}