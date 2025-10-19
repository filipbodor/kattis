#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    map<int, priority_queue<int, vector<int>, greater<int>>> ints;

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        ints[a].push(b);
    }

    map<int, int> p;

    int counter = 0;
    int c = 0;

    for (auto i = ints.begin(); i != ints.end(); i++) {
        auto a = *i;

        while (!a.second.empty()) {
            int aa = a.second.top(); a.second.pop();

            // printf("%d -> %d\n", a.first, aa);
        
            if (c == 0) {
                counter++;
                p[aa]++;
                c++;
            } else {
                while (p.size() != 0 && (*p.begin()).first < a.first) {
                    c -= (*p.begin()).second;
                    p.erase(p.begin());
                }

                if (c == k) {
                    auto b = p.end();
                    b--;
                    if (aa < (*b).first) {
                        if ((*b).second == 1) {
                            p.erase(b);
                        } else {
                            (*b).second--;
                        }
                        p[aa]++;
                    }
                } else {
                    p[aa]++;
                    counter++;
                    c++;
                }
            }

            // for (auto j = p.begin(); j != p.end(); j++) {
            //     printf("%d[%d] ", (*j).first, (*j).second);
            // }
            // printf(": %d\n\n", p.size());
        }
    }

    printf("%d\n", counter);

    return 0;
}