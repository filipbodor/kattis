#include <bits/stdc++.h>
using namespace std;

long long n, k, t1, t2;
vector<long long> meas;
vector<pair<long long, long long>> ints;

double daq(int type, long long left, long long right) {
    //printf("%d %d %d\n", type, left, right);
    if (type == k) return ((long double)(right - left) / (long double)(t2 - t1));
    double probability = 0.0;
    long long curLeft = left;
    int idx = meas.end() - lower_bound(meas.begin(), meas.end(), ints[type].first - left) - 1;
    for (int i = min(n - 1, n - idx); i >= 0 && curLeft < right; --i) {

        if (ints[type].second - meas[i] <= curLeft) {
            continue;

        } else if (ints[type].first - meas[i] <= curLeft && ints[type].second - meas[i] > curLeft) {
            curLeft = ints[type].second - meas[i];
            continue;

        } else if (ints[type].first - meas[i] > curLeft) {
            probability += daq(type + 1, curLeft, min(right, ints[type].first - meas[i]));
            curLeft = ints[type].second - meas[i];
        }
    }
    if (curLeft < right) {
        probability += daq(type + 1, curLeft, right);
    }
    return probability;
}

int main() {

    scanf("%ld %ld %ld %ld", &n, &k, &t1, &t2);

    meas.assign(n, 0.0);
    ints.assign(k, {});

    for (int i = 0; i < n; i++) {
        scanf("%ld", &meas[i]);
    }



    for (int i = 0; i < k; i++) {
        long long a, b;
        scanf("%ld %ld", &a, &b);
        ints[i] = {a, b};
    }


    double res = daq(0, t1, t2);

    printf("%lf\n", res);




    return 0;
}