#include <bits/stdc++.h>
using namespace std;

int digits(int n) {
    int counter = 0;
    while (n != 0) {
        counter += n % 10;
        n /= 10;
    }
    return counter;
}

int main() {

    int a;

    while (scanf("%d", &a) == 1 && a != 0) {
        
        int i;
        for (i = 11; i <= 100 && digits(a) != digits(i*a) ; i++);

        printf("%d\n", i);
    }

    return 0;
}