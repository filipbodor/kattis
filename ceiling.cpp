#include <bits/stdc++.h>
using namespace std;

struct BNode {
    int value;
    BNode *left;
    BNode *right;
    BNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

void insert(int a, BNode *&node) {
    if (!node) {
        node = new BNode(a);
        return;
    }

    if (a > node->value) {
        return insert(a, node->right);
    } 
    return insert(a, node->left);
}

bool isSame(BNode *one, BNode *second) {
    if (one && second) {
        return isSame(one->left, second->left) && isSame(one->right, second->right);
    } else if (!one && !second) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<BNode*> trees {};

    for (int i = 0; i < n; i++) {
        BNode *tree = nullptr;
        
        for (int j = 0; j < m; j++) {
            int a;
            scanf("%d", &a);
            insert(a, tree);
        }

        bool flag = true;
        for (int j = 0; j < trees.size() && flag; j++) {
            flag = !isSame(trees[j], tree);
        }   
        if (flag) trees.emplace_back(tree); 
    }

    printf("%d\n", trees.size());




    return 0;
}