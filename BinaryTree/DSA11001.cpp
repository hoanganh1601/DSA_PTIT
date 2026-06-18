#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct node {
    char data;
    node *left;
    node *right;

    node (char c) {
        data = c;
        left = NULL;
        right = NULL;
    }
};

void inOrder(node *root) {
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        string s;
        cin >> s;
        
        stack<node*> st;
        node *root = NULL;
        for (char c : s) {
            if(isalpha(c)) {
                st.push(new node(c));
            }
            else {
                node *tmp = new node(c);

                node *x1 = st.top(); st.pop();
                node *x2 = st.top(); st.pop();

                tmp->left = x2;
                tmp->right = x1;

                st.push(tmp);
            }
        }
        root = st.top();

        inOrder(root);
        cout << endl;
    }

    return 0;
}