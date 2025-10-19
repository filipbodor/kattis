#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    vector<int> arrows(1000001, 0);

    int counter = 0;

    for (int i = 0; i < n; i++) {
        if (arrows[h[i]] != 0) {
            arrows[h[i]]--;
        } else {
            counter++;
        }
        arrows[h[i] - 1]++;
    }
    

    printf("%d\n", counter);

    return 0;
}