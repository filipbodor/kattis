#include <bits/stdc++.h>
using namespace std;

int cou(int a) {
    if (a == 1) return 2;
    return 1 + cou((int)log10(a) + 1);
}

int main() {
    char a;

    while (scanf("%c", &a) == 1 && a != 'E') {
        int counter = 1;
        bool flag = (a == '1');

        while (scanf("%c", &a) == 1 && a != '\n') {
            counter++;
        }

        if (counter == 1 && flag) {
            printf("1\n");
        } else {
            int res = cou(counter);

            printf("%d\n", res);
        }
        

    }

    scanf("ND");

    return 0;
}