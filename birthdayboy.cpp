#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> m {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> acm {0, 0}; for (int i = 1; i <= 12; i++) {
        acm.push_back(acm[i] + m[i]);
    }

    vector<int> d(365, 0);

    vector<int> days;
    vector<int> dates;

    int first = -1;

    for (int i = 0; i < n; i++) {
        char str[25];
        int a, b;
        scanf("%s %d-%d", &str, &a, &b);

        if (first == -1) first = acm[a] + b - 1; 

        d[acm[a] + b - 1] = 1;
    }


    int inx = first;
    int last = first;
    int curDays = 0;
    for (int i = 1; i <= 365; i++) {
        inx = (first + i) % 365;
        curDays++;

        if (d[inx] == 1) {
            days.push_back(curDays);
            dates.push_back(inx);
            curDays = 0;
        }

    }

    int start = acm[10] + 28;

    int maxIdx = 0;

    for (int i = 1; i < days.size(); i++) {
        if (days[maxIdx] == days[i]) {
            if ((dates[maxIdx] + 365 - start) % 365 > (dates[i] + 365 - start) % 365) {
                maxIdx = i;
            }
            
        } else if (days[maxIdx] < days[i]) {
            maxIdx = i;
        }
    }

    int birthday = (dates[maxIdx] + 365 - 1) % 365;
    int month; 
    for (month = 0; month < 12 && acm[month + 1] <= birthday; month++);

    printf("%0.2d-%0.2d\n", month, birthday - acm[month] + 1);

    return 0;
}