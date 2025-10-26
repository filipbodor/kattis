#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> in(100);

    for (int &i : in) {
        scanf("%d", &i);
    }

    
    printf("%d\n", in[99] % 10 == 0 ? 10 : in[99] % 10);

    return 0;
}