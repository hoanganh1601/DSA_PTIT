#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct node {
    int data;
    node *left;
    node *right;
    node(int u) {
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

int heightTree(node *root) {
    // empty tree
    if(root == NULL) return 0;
    return max(heightTree(root->left), heightTree(root->right)) + 1;
}

bool checkLeaf(node *root, int curLevel, int height) {
    if(root == NULL) return true;

    if(root->left == NULL && root->left == NULL && curLevel < height) return false;
    
    return checkLeaf(root->left, curLevel + 1, height) && checkLeaf(root->right, curLevel + 1, height);
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test; 
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

        int h = heightTree(root);
        cout << checkLeaf(root, 1, h) << endl;
    }

    return 0;
}