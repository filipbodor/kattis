#include <bits/stdc++.h>
using namespace std;

int l_b(int left, int right, vector<int> &p, int a) {
    for (int i = 0; i < 15 && left < right; i++) {
        int mid = (left + right) / 2 + 1;
        if (p[mid] == a) {
            return mid;
        } else if (p[mid] < a) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int findClosest(int a, vector<int> &nums) {
    int closest = nums[0] + nums[1];

    for (int i = 0; i < (int)nums.size() - 1; i++) {
        int l = l_b(i + 1, nums.size() - 1, nums, a - nums[i]);
        int b = nums[l] + nums[i];

        if (l < nums.size() - 1) {
            int c = nums[l+1] + nums[i];
            if (min({abs(a - c), abs(a - b), abs(a - closest)}) == abs(a - c)) {
                closest = c;
            } else if (min({abs(a - c), abs(a - b), abs(a - closest)}) == abs(a - b)) {
                closest = b;
            }
        } else if (min({abs(a - b), abs(a - closest)}) == abs(a - b)) {
            closest = b;
        }
    }

    return closest;
}

int main() {

    int n;
    int idx = 0;
    while (scanf("%d", &n) != EOF) {
        idx++;

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }


        sort(nums.begin(), nums.end());

        int m;
        scanf("%d", &m);

        printf("Case %d:\n", idx);

        for (int i = 0; i < m; i++) {
            int a;
            scanf("%d", &a);

            int clo = findClosest(a, nums);

            printf("Closest sum to %d is %d.\n", a, clo);
        }
    }

    return 0;
}