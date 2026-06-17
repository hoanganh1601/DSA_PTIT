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

void makeRoot(node *root, int u, int v, char c) {
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c) {
    if(root == NULL) return;
    if(root->data == u) {
        makeRoot(root, u, v, c);
        return;
    }

    insertNode(root->left, u, v, c);
    insertNode(root->right, u, v, c);
}

void levelOrder(node *root) {
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node *tmp = q.front(); q.pop();
        cout << tmp->data << " ";
        if(tmp->left != NULL) q.push(tmp->left);
        if(tmp->right != NULL) q.push(tmp->right);
    }
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
                makeRoot(root, u, v, c);
            }

            else {
                insertNode(root, u, v, c);
            }
        }

        levelOrder(root);
        cout << endl;
    }

}