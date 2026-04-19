#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int n, k;
int a[101];
bool visited[101];
bool ok;
int subSum;

void Try(int cnt, int curSum, int start) {
    
    if(ok) return;
    
    if(cnt == k) {
        ok = true;
        return;
    }

    if(curSum == subSum) {
        Try(cnt + 1, 0, 0);
        return;
    }

    for (int i = start; i < n; ++i) {
        if(!visited[i]) {
            if(curSum + a[i] <= subSum) {
                visited[i] = true;
                Try(cnt, curSum + a[i], i + 1);
                visited[i] = false;
            }

        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;

    while(test--) {
        cin >> n >> k;
        int sum = 0;
        ok = false;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            visited[i] = false;
        }

        if(sum % k != 0) cout << 0 << endl;
        else {
            subSum = sum / k;
            Try(0, 0, 0);
            cout << ok << endl;
        } 
    }

    return 0;
}