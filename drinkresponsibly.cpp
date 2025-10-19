#include <bits/stdc++.h>
using namespace std;

int d;
int im;
double m, u;

double ERR = 1e-3;

vector<string> names;
vector<int> sizes;
vector<int> prices;
vector<int> perce;
vector<double> ppp;

vector<vector<unordered_map<double, int>>> memo; 
vector<vector<unordered_map<double, tuple<int, int, double>>>> parent;

double ans_alc;

int dp(int type, int price, double alcohol) {
    //printf("%d %d %lf %d\n", type, price, alcohol, (im == price && alcohol == u));
    if (type == d) {
        if (im == price && abs(u - alcohol) <= ERR) ans_alc = alcohol;
        return 1 + (im == price && abs(u - alcohol) <= ERR);
    }
    if (price > im || alcohol > u + ERR) return 1;

    int &ans = memo[type][price][alcohol];
    if (ans != 0) return ans;

    if (dp(type, price + prices[type], alcohol + ppp[type]) == 2) {
        parent[type][price + prices[type]][alcohol + ppp[type]] = {type, price, alcohol};
        return ans = 2;
    }

    if (dp(type + 1, price, alcohol) == 2) {
        parent[type + 1][price][alcohol] = {type, price, alcohol};
        return ans = 2;
    }


    return ans = 1;
}

int main() {
    scanf("%lf %lf %d", &m, &u, &d);

    im = m * 100;

    
    names.assign(d, "");
    sizes.assign(d, 0);
    prices.assign(d, 0);
    perce.assign(d, 0);
    ppp.assign(d, 0.0);


    for (int i = 0; i < d; i++) {
        char name[25];
        int c;
        double a;

        scanf("%s %d %d/%d %lf", &name, &perce[i], &c, &sizes[i], &a);
        prices[i] = a * 100;
        names[i] = name;
        ppp[i] = round((double)perce[i] / (double)sizes[i] * 10000.0) / 10000.0;
    }

    memo.assign(10, vector<unordered_map<double, int>>(2000));
    parent.assign(10, vector<unordered_map<double, tuple<int, int, double>>>(2000));
    int res = dp(0, 0, 0);

    if (res == 1) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    unordered_map<string, int> cou;
    auto &[type, price, alcohol] = parent[d][im][ans_alc];
    while (!(type == 0 && price == 0 && alcohol == 0)) {
        auto &[o, f, g] = parent[type][price][alcohol];
        if (o == type) cou[names[type]]++;

        alcohol = g;
        price = f;
        type = o;
    }


    for (int i = 0; i < d; i++) {
        printf("%s %d\n", names[i].c_str(), cou[names[i]]);
    }

    return 0;
}