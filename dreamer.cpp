#include <bits/stdc++.h>
using namespace std;

vector<int> days {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int validate(vector<int> &a) {
    int day = a[0] * 10 + a[1];
    int month = a[2] * 10 + a[3];
    int year = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];

    if (year >= 2000) {
        if (month <= 12 && month > 0) {
            if (month == 2 && ((year % 4 == 0 && (year % 400 == 0 || year % 100 != 0) && (day <= 29 && day > 0)) || (day <= 28 && day > 0) )) {
                return 1;
            } else if (day <= days[month] && day > 0) {
                return 1;
            }
        }
    }

    return 0;
}

vector<int> minDate(vector<int> &a, vector<int> b) {
    int day = a[0] * 10 + a[1];
    int month = a[2] * 10 + a[3];
    int year = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];
    
    int day2 = b[0] * 10 + b[1];
    int month2 = b[2] * 10 + b[3];
    int year2 = b[4] * 1000 + b[5] * 100 + b[6] * 10 + b[7];

    if (year < year2) {
        return a;
    } else if (year > year2) {
        return b;
    } else if (month < month2) {
        return a;
    } else if (month > month2) {
        return b;
    } else if (day < day2) {
        return a;
    } else if (day > day2) {
        return b;
    } 
    return a;
}

int main() {    
    int T;
    scanf("%d\n", &T);

    while (T--) {
        char a;

        vector<int> date(8);
        for (int i = 0; i < 8; i++) {
            scanf(" %c", &a);
            date[i] = (a - '0');
        }

        sort(date.begin(), date.end());

        vector<int> mi = {10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000};

        int cou = 0;
        do {
            if (validate(date)) {
                cou++;
                mi = minDate(mi, date);
            }
        } while (next_permutation(date.begin(), date.end()));

        if (cou == 0) {
            printf("0\n");
        } else {
            printf("%d %d%d %d%d %d%d%d%d\n", cou, mi[0], mi[1], mi[2], mi[3], mi[4], mi[5], mi[6], mi[7]);
        }
    }


    return 0;
}