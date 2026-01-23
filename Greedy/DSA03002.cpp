#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int minToMax(string s) {
    for(int i = 0; s[i]; ++i) {
        if(s[i] == '5') s[i] = '6';
    }
    return stoi(s);
}

int maxToMin(string s) {
    for (int i = 0; s[i]; ++i) {
        if(s[i] == '6') s[i] = '5';
    }
    return stoi(s);
}

signed main(){

    speed;  

    string a, b;
    cin >> a >> b;
    
    cout << maxToMin(a) + maxToMin(b) << " " << minToMax(a) + minToMax(b);
    

    return 0;
}