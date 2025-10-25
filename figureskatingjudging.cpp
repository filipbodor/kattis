#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> nums(n);

    double su = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        su += nums[i];
    }

    sort(nums.begin(), nums.end());


    vector<long double> pref(n+1, 0.0L), prefsq(n+1, 0.0L);
    for (int i = 0; i < n; ++i) {
        pref[i+1] = pref[i] + (long double)nums[i];
        prefsq[i+1] = prefsq[i] + (long double)nums[i] * (long double)nums[i];
    }

    long double best = numeric_limits<long double>::infinity();
    for (int i = 0; i + k <= n; ++i) {
        long double sum = pref[i+k] - pref[i];
        long double sumsq = prefsq[i+k] - prefsq[i];
        long double badness = sumsq - (sum * sum) / (long double)k;
        if (badness < best) best = badness;
    }


    printf("%llf\n", best);

    return 0;
}