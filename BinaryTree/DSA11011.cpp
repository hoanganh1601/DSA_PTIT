#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct node {
    int data;
    node *left;
    node *right;

    node (int u) {
        data = u;
        left = NULL;
        right = NULL;
    }
};

void makeNode(node *root, int u, int v, char c) {
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c) {
    if(root == NULL) return;
    if(root->data == u) {
        makeNode(root, u, v, c);
        return;
    }

    insertNode(root->left, u, v, c);
    insertNode(root->right, u, v, c);
}

bool fullBinaryTree(node *root) {

    // An empty tree is technically valid 
    if(root == NULL) return true;

    // A leaf node (0 child) is valid   
    if(root->left == NULL && root->right == NULL) return true;

    if(root->left == NULL && root->right != NULL) return false;
    if(root->left != NULL && root->right == NULL) return false;

    return fullBinaryTree(root->left) && fullBinaryTree(root->right);
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        int n; cin >> n;
        node *root = NULL;
        for (int i = 1; i <= n; ++i) {
            int u, v; char c;
            cin >> u >> v >> c;
            if(root == NULL) {
                root = new node(u);
                makeNode(root, u, v, c);
            }
            else {
                insertNode(root, u, v, c);
            }
        }
        cout << fullBinaryTree(root) << endl;
    }


    return 0;
}