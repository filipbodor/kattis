#include <bits/stdc++.h>
using namespace std;

int N, t;
vector<long long> a;


void e1() {
    printf("7\n");
}

void e2() {
    if (a[0] > a[1]) printf("Bigger\n");
    else if (a[0] == a[1]) printf("Equal\n");
    else if (a[0] < a[1]) printf("Smaller\n");
}

void e3() {
    sort(a.begin(), a.begin() + 3);
    printf("%ld\n", a[1]);
}

void e4() {
    long long sum = 0;
    for (long long i : a) sum += i;
    printf("%ld\n", sum);
}

void e5() {
    long long sum = 0;
    for (long long i : a) if (i % 2 == 0) sum += i;
    printf("%ld\n", sum);
}

void e6() {

    string s = "";
    for (long long i : a) s += (char)(i % 26 + 'a');
    printf("%s\n", s.c_str());
}

void e7() {
    vector<int> visited(N, -1);

    long long i = 0;
    while (i != N-1) {

        if (i > N-1) {
            printf("Out\n");
            return;
        }

        if (visited[i] == 1) {
            printf("Cyclic\n");
            return;
        }

        visited[i] = 1;
        i = a[i];
    }
    printf("Done\n");
}

int main() {
    scanf("%d %d", &N, &t);

    a.assign(N, 0);

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    if (t == 1) {
        e1();
    } else if (t == 2) {
        e2();
    } else if (t == 3) {
        e3();
    } else if (t == 4) {
        e4();
    } else if (t == 5) {
        e5();
    } else if (t == 6) {
        e6();
    } else if (t == 7) {
        e7();
    }


    return 0;
}