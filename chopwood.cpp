#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> nums(n);
    vector<int> chopped(n+2, 0);
    vector<int> res(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    if (nums[n-1] != n+1) {
        printf("Error\n");
        return 0;
    }

    chopped[n+1] = 1;

    int high = n;


    for (int i = n-1; i > 0; i--) {
        if (nums[i] != nums[i-1] && !chopped[nums[i-1]]) {
            chopped[nums[i-1]] = 1;
            res[i] = nums[i-1];
        } else {
            while (chopped[high]) high--;
            res[i] = high;
            chopped[high] = 1;
        }
    }

    while (chopped[high]) high--;
    res[0] = high;

    for (int i : res) {
        printf("%d\n", i);
    }


    

    return 0;
}