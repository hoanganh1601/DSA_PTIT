#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct node {
    int data;
    node *left, *right;
    node (int u) {
        data = u;
        left = NULL;
        right = NULL;
    }
};

int level[1005], n;

node *insert(node *root, int key) {
    if(root == NULL) {
        return new node(key);
    }
    
    if(key < root->data) {
        root->left = insert(root->left, key);
    }
    else if(key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

void preOrder(node *root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> n;
        node *root = NULL;
        for (int i = 0; i < n; ++i) {
            cin >> level[i];
            root = insert(root, level[i]);
        }

        preOrder(root);
        cout << endl;
    }

    return 0;
}