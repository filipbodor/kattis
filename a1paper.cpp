#include <bits/stdc++.h>
using namespace std;

double sizes[2] = {pow(2, -(3.0 / 4.0)), pow(2, -(5.0 / 4.0))};
int papers[3];
int n;

double makeAx(int type, int size) {
    if (type >= n) return -1;
    double ans = 0.0;

    int s = size - papers[type]; 

    if (s > 0) {
        double res = makeAx(type + 1, s * 2);
        if (res == -1) return -1;
        ans += res;
    }
    ans += ((double)size / 2.0) * ((double)sizes[type % 2] / (double)(pow(2, (int)type / 2)));
    return ans;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &papers[i]);
    }

    double size = makeAx(0, 2);
    if (size == -1) {
        printf("impossible\n");
    } else {
        printf("%f\n", size);
    }

    return 0;
}