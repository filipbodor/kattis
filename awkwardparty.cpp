#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    vector<int> arr(n);
    unordered_map<int, int> lastSeen;

    int mi = n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (lastSeen.count(arr[i]) != 0) {
            mi = min(mi, i - lastSeen[arr[i]]);
        }
        lastSeen[arr[i]] = i;
    }

    printf("%d\n", mi);



    return 0;
}