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

void makeNode(node *root, int u, int v, char c) {
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c) {
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node *cur = q.front(); q.pop();
        
        if(cur->data == u) {
            makeNode(cur, u, v, c);
            return;
        }

        if(cur->left != NULL) q.push(cur->left);
        if(cur->right != NULL) q.push(cur->right); 
    }
}

void init(node *root, vector<int> &val) {
    if(root == NULL) return;

    val.push_back(root->data);
    init(root->left, val);
    init(root->right, val);
}

void convert(node *root, vector<int> val, int &curIdx) {
    if(root == NULL) return;

    // Go left
    convert(root->left, val, curIdx);

    root->data = val[curIdx];
    ++curIdx;

    // Go right
    convert(root->right, val, curIdx);
}

void inOrder(node *root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
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
            else insertNode(root, u, v, c);
        }

        vector<int> val; // gía trị của của các node trong mảng
        init(root, val);

        sort(val.begin(), val.end());

        int idx = 0;
        convert(root, val, idx);

        inOrder(root);
        cout << endl;
    }

    return 0;
}