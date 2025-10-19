#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, B;
    while (scanf("%d %d", &N, &B) == 2 && N != -1) {

        vector<double> votes(N);
        priority_queue<tuple<double, int, int>> pq;

        for (int i = 0; i < N; i++) {
            scanf("%lg", &votes[i]);
            pq.push({votes[i], 1, i});
        }

        for (int i = 0; i < B - N; i++) {
            auto [a, b, c] = pq.top(); pq.pop();
            b++;
            double d = votes[c] / (double)b;
            pq.push({d, b, c});
        }


        auto [a, b, c] = pq.top();
        
        printf("%d\n", (int)ceil(a));
    }

    return 0;
}