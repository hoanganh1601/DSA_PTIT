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

// tất cả các node đều có 2 node con, tất cả các node lá đều cùng một mức
bool full(node *root) {
    if(root == NULL) return true;

    if(root->left == NULL && root->right == NULL) return true;

    if(root->left == NULL && root->right != NULL) return false;
    if(root->left != NULL && root->right == NULL) return false;
    
    return full(root->left) && full(root->right);
}

bool complete(node *root, int curHeight, int maxDepth) {
    if(root == NULL) return true;
    if(root->right == NULL && root->left == NULL && curHeight < maxDepth) {
        return false;
    }

    return complete(root->left, curHeight + 1, maxDepth) && complete(root->right, curHeight + 1, maxDepth);
}

int height(node *root) {
    if(root == NULL) return 0;

    return max(height(root->left), height(root->right)) + 1;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;   cin >> test;
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
            else insertNode(root, u, v, c);
        }

        int h = height(root);
        
        if(full(root) && complete(root, 1, h)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
