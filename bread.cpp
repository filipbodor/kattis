#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> nums1(n+1);
    
    vector<int> nums2(n+1);
    vector<int> priority1(n+1);
    vector<int> priority2(n+1);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums1[i]);
        priority1[nums1[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums2[i]);
        priority2[nums1[i]] = i;
    }

    int a, b;
    
    for (int i = 1; i <= n; i++) {
        if (nums1[n - 1] == nums2[i]) a = i;
        if (nums1[n] == nums2[i]) b = i;
    }

    if (a < b) {
        printf("Possible\n");
    } else {
        printf("Impossible\n");
    }

    return 0;
}