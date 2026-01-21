#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void Try(int n, char from, char to, char mid) {
    
    // only one
    if(n == 1) {
        cout << from << " -> " << to << endl;
        return;
    }

    // Move N - 1 plates from A to B
    Try(n - 1, from, mid, to);

    // Move Nth plate from A to C
    cout << from << " -> " << to << endl;

    // Move N - 1 plates from B --> C
    Try(n - 1, mid, to, from);
}

signed main(){

    speed;  

    int n;
    cin >> n;
    Try(n, 'A', 'C', 'B');

    return 0;
}