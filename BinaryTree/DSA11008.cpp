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

void SprialOrder(node *root) {
    stack<node*> st1, st2;
    st1.push(root);

    while(!st1.empty() || !st2.empty()) {
        while(!st1.empty()) {
            node *tmp = st1.top(); st1.pop();
            cout << tmp->data << " ";
            if(tmp->right != NULL) st2.push(tmp->right);
            if(tmp->left != NULL) st2.push(tmp->left);
        }

        while(!st2.empty()) {
            node *tmp = st2.top(); st2.pop();
            cout << tmp->data << " ";
            if(tmp->left != NULL) st1.push(tmp->left);
            if(tmp->right != NULL) st1.push(tmp->right);
        }
    }
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
                makeRoot(root, u, v, c);
            }
            else insertNode(root, u, v, c);
        }
        SprialOrder(root);
        cout << endl;
    }


    return 0;
}