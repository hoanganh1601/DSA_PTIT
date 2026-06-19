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

void insertNode(node *root, int u, int v, char c) {
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()) {
        node *cur = q.front(); 
        q.pop();

        if(cur->data == u) {
            if(c == 'L' && cur->left == NULL) {
                cur->left = new node(v);
                return; 
            }
            else if(c == 'R' && cur->right == NULL) {
                cur->right = new node(v);
                return; 
            }
        }

        if(cur->left != NULL) q.push(cur->left);
        if(cur->right != NULL) q.push(cur->right); 
    }
}

int maxSum(node *root, int &ans) {
    if(root == NULL) return 0;

    // leaf node
    if(root->left == NULL && root->right == NULL) {
        return root->data;
    }

    // đi xuống 2 nhánh trái và phải
    int left = maxSum(root->left, ans);
    int right = maxSum(root->right, ans);

    // node có đủ 2 con (uốn chữ V)
    if(root->left != NULL && root->right != NULL) {
        ans = max(ans, left + right + root->data); // Cập nhật chữ V hiện tại (có phải tổng lớn nhất hay không)
        return max(left, right) + root->data; // truyền lên node cha ở trên để xét tiếp
    }

    if(root->left == NULL) return right + root->data; // đi bên phải
    if(root->right == NULL) return left + root->data; // đi bên trái

    return 0;
}

void deleteTree(node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
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
                if(c == 'L') root->left = new node(v);
                else root->right = new node(v);
            }
            else insertNode(root, u, v, c);
        }
        int ans = INT_MIN;
        maxSum(root, ans);

        cout << ans << endl;

        deleteTree(root);
    }


    return 0;
}