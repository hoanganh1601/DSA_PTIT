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

unordered_map<int, node*> mp;

void makeNode(int u, int v, char c) {
    if(c == 'L') {
        mp[u]->left = new node(v);
        mp[v] = mp[u]->left;
    }
    else {
        mp[u]->right = new node(v);
        mp[v] = mp[u]->right;
    }
}

// tong ca node la ben phai 
int sumRight(node *root, bool isRight) {
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) {
        if(isRight) return root->data;
        else return 0;
    }

    return sumRight(root->left, false) + sumRight(root->right, true);
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
                mp[u] = root;
                makeNode(u, v, c);
            }
            else makeNode(u, v, c);
        }

        cout << sumRight(root, 0) << endl;
        mp.clear();
    }

    return 0;
}