#include <bits/stdc++.h>
using namespace std;

int memo[1 << 20];
vector<int> nums;
int n;
unordered_map<int, int> se;  

bool dp(int mask, int sum) {
    if (!mask) return true;

    int &ans = memo[mask];
    if (ans != -1) return ans;

    if (se.find(sum) != se.end() && se[sum] != 0) {
        int m = ((1 << n) - 1) & (~mask);
        while (m) {
            int r = m & -m;
            int ctz = __builtin_ctz(r);

            printf("%d ", nums[ctz]);

            m ^= r;
        }   
        printf("\n");
        m = se[sum];
        while (m) {
            int r = m & -m;
            int ctz = __builtin_ctz(r);

            printf("%d ", nums[ctz]);

            m ^= r;
        }   
        printf("\n");
        return false;

    }
    se[sum] = ((1 << n) - 1) & (~mask);

    int m = mask;

    ans = true;
    while (m && ans) {
        int r = m & -m;
        int ctz = __builtin_ctz(r);

        ans = dp(mask^r, sum + nums[ctz]);

        m ^= r;
    }
    return ans;
}

int main() {
    int T, idx = 1;
    scanf("%d", &T);

    while (T--) {

        scanf("%d", &n);

        nums.assign(n, 0);

        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        memset(memo, -1, sizeof(memo));
        se.clear();

        printf("Case #%d:\n", idx);
        bool ans = dp((1 << n) - 1, 0);

        if (ans) printf("Impossible\n");

        idx++;

    }

    return 0;
}