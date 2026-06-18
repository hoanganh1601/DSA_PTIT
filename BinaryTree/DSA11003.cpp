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

int preOrder[1004];
int inOrder[1004];
unordered_map<int, int> idx;
int curIdx;

node *build(int left, int right) {
    if(left > right) return NULL;
    node *root = new node(preOrder[curIdx]);
    int m = idx[preOrder[curIdx]]; 
    ++curIdx;

    root->left = build(left, m - 1);
    root->right = build(m + 1, right);

    return root;
}

void postOrder(node *root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        
        for (int i = 1; i <= n; ++i) {
            cin >> inOrder[i];
            idx[inOrder[i]] = i;
        }   

        for (int i = 1; i <= n; ++i) {
            cin >> preOrder[i];
        }

        curIdx = 1; // first
        node *root = build(1, n);
        postOrder(root);
        cout << endl;

        idx.clear();
    }

    return 0;
}