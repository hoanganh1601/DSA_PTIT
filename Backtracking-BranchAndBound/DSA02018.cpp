#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

bool checkExpression(int index, int current_val, vector<int>& perm) {
    if (index == 5) {
        return current_val == 23;
    }

    if (checkExpression(index + 1, current_val + perm[index], perm)) return true;
    if (checkExpression(index + 1, current_val - perm[index], perm)) return true;
    if (checkExpression(index + 1, current_val * perm[index], perm)) return true;

    return false;
}

bool Try(int step, vector<int>& a, vector<int>& perm, vector<bool>& used) {
    if (step == 5) {
        return checkExpression(1, perm[0], perm);
    }

    for (int j = 0; j < 5; ++j) {
        if (!used[j]) {
            used[j] = true;
            perm[step] = a[j];
            
            if (Try(step + 1, a, perm, used)) {
                return true;
            }
            
            used[j] = false;
        }
    }
    
    return false;
}

void solve() {
    vector<int> arr(5);
    for (int i = 0; i < 5; ++i) cin >> arr[i];
    

    vector<int> perm(5);
    vector<bool> used(5, false);

    if (Try(0, arr, perm, used)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}