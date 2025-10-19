#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a;
    scanf("%d", &n);

    int counter = 0;
    vector<vector<int>> recipes(n);

    unordered_map<int, int> in;

    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        vector<int> recipe(m);
        unordered_map<int, bool> recipeIn;
        for (int j = 0; j < m; j++) {
            scanf("%d", &recipe[j]);
            recipeIn[recipe[j]] = 0;
        }
        bool flag = true;
        for (int j = 0; j < m && flag; j++) {
            if (in.find(recipe[j]) != in.end() && !recipeIn[recipe[j]]) {
                for (int k : recipes[in[recipe[j]]]) {
                    if (recipeIn.find(k) != recipeIn.end()) {
                        recipeIn[k] = 1;
                    } else {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
        }
        if (flag) {
            counter++;
            recipes[i] = recipe;
            for (int rec : recipe) in[rec] = i;
        }
    }

    printf("%d\n", counter);


    return 0;
}