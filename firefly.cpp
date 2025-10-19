#include <bits/stdc++.h>
using namespace std;

int binarySearch(int left, int right, int val, vector<int> &a) {
    for (int i = 0; i < 20 && left < right; i++) {
        int mid = (left + right) / 2;
        if (a[mid] == val) {
            right = mid;
            break;
        } else if (a[mid] > val) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (right == (int)a.size() - 1 && a[right] < val) right = a.size();
    else while (right - 1 >= 0 && a[right] == a[right - 1]) right--;
    return right;
}

int main() {
    int n, h;

    scanf("%d %d", &n, &h);

    vector<int> up(n / 2);
    vector<int> down(n / 2);
    

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) scanf("%d", &down[i / 2]);
        else scanf("%d", &up[i / 2]);
    }

    sort(up.begin(), up.end());
    sort(down.begin(), down.end());

    int size = n / 2;



    pair<int, int> mi = {1e9, 0};
    for (int i = 1; i <= h; i++) {
        int a = binarySearch(0, size - 1, h - i + 1, up);
        int b = binarySearch(0, size - 1, i, down);

        int x = (size - a) + (size - b);
        if (mi.first > x) {
            mi = {x, 1};
        } else if (mi.first == x) {
            mi.second++;
        }

        //printf("%d %d val: %d, mi.first: %d mi.second: %d num: %d checking: [%d %d]\n", a, b, i, mi.first, mi.second, x, h - i + 1, i);
    }

    printf("%d %d\n", mi.first, mi.second);


    return 0;
}