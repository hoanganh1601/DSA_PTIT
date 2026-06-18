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

int in[1005], level[1005];
unordered_map<int, int> idx;
int n;

node *build(int i, int left, int right) {
    if(left > right || i >= n) return NULL;

    node *root = new node(level[i]);
    int tmp = idx[level[i]];

    root->left = build(2 * i + 1, left, tmp - 1);
    root->right = build(2 * i + 2, tmp + 1, right);
    
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
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> in[i];
            idx[in[i]] = i;
        }
        for (int i = 0; i < n; ++i) cin >> level[i];

        node *root = build(0, 0, n - 1);
        postOrder(root);
        cout << endl;

        idx.clear();
    }

    return 0;
}