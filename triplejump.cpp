#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int a = nums[0] / 3;
    int c;
    int b = nums[n-1] / 3;

    int aa = a + a;

    for (int i = 1; i < n; i++) {
        if (nums[i] - aa != a && nums[i] - aa != b) {
            c = nums[i] - aa;
            break;
        } 
    }

    printf("%d %d %d\n", a, c, b);

    return 0;
}