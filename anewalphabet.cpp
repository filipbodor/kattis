#include <bits/stdc++.h>
using namespace std;

const char *trans[26] = {
    "@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"
};


int main() {



    char c;
    while (scanf("%c", &c)) {
        if (c == '\n') break;

        if (c <= 'z' && c >= 'a') printf("%s", trans[c - 'a']);
        else if (c <= 'Z' && c >= 'A') printf("%s", trans[c - 'A']);
        else printf("%c", c);


    }

    printf("\n");

    return 0;



}