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

bool check(node *root1, node *root2) {
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 != NULL && root2 != NULL) {
        return root1->data == root2->data && check(root1->left, root2->left)
            && check(root1->right, root2->right);
    }

    return false;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        int n1; cin >> n1;
        
        node *root1 = NULL;
        for (int i = 1; i <= n1; ++i) {
            int u, v; char c;
            cin >> u >> v >> c;

            if(root1 == NULL) {
                root1 = new node(u);
                makeNode(root1, u, v, c);
            }
            else insertNode(root1, u, v, c);
        }

        int n2; cin >> n2;
        node *root2 = NULL;
        for (int i = 1; i <= n2; ++i) {
            int u, v; char c;
            cin >> u >> v >> c;
            if(root2 == NULL) {
                root2 = new node(u);
                makeNode(root2, u, v, c);
            }
            else insertNode(root2, u, v, c);
        }

        cout << check(root1, root2) << endl;
    }

    return 0;
}