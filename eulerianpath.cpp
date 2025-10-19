#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<int> cntIn;
vector<int> cntOut;
int n, m;

vector<int> hierholzer(int s) {
    vector<int> ans, idx(n, 0), st;
    st.push_back(s);
    while(!st.empty()) {
        int u = st.back();
        
        if (idx[u] < (int)AL[u].size()) {
            st.push_back(AL[u][idx[u]]);
            ++idx[u];
        } else {
            ans.push_back(u);
            st.pop_back();
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    while (scanf("%d %d", &n, &m) == 2 && !(n == 0 && m == 0)) {
        AL.assign(n, {});
        cntIn.assign(n, 0);
        cntOut.assign(n, 0);

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            AL[a].push_back(b);
            cntOut[a]++;
            cntIn[b]++;
        }

        int cIn = 0, cOut = 0;
        bool flag = true;
        for (int i = 0; i < n && flag; i++) {
            if (cntIn[i] == cntOut[i]) continue;
            else if (abs(cntIn[i] - cntOut[i]) > 1) flag = false;
            else if (cntIn[i] > cntOut[i]) cIn++;
            else if (cntIn[i] < cntOut[i]) cOut++;
        }

        flag &= (cIn <= 1 && cOut == cIn);

        if (!flag) {
            printf("Impossible\n");
            continue;
        }
        int s = -1;
        for (int i = 0; i < n; i++) {
            if (s == -1 && cntOut[i] > 0) s = i; 
            if (cntOut[i] - cntIn[i] == 1) s = i; 
        }

        vector<int> ans = hierholzer(s);

        if ((int)ans.size() != m+1) {
            printf("Impossible\n");
            continue;
        }

        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");

    }

    return 0;
}