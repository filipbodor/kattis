#include <bits/stdc++.h>
using namespace std;

int main() {


    int DAT[4];
    for (int i = 0; i < 4; i++) DAT[i] = 0;

    char c;
    double size = 0;
    while (scanf("%c", &c) == 1) {
        if (c == '\n') break;
        
        if (c == '_') {
            DAT[0]++;
        } else if (c >= 'a' && c <= 'z') {
            DAT[1]++;
        } else if (c >= 'A' && c <= 'Z') {
            DAT[2]++;
        } else {
            DAT[3]++;
        }
        size++;
    }

    printf("%lf\n",  (double)DAT[0] / size);
    printf("%lf\n",  (double)DAT[1] / size);
    printf("%lf\n",  (double)DAT[2] / size);
    printf("%lf\n",  (double)DAT[3] / size);

    return 0;
}