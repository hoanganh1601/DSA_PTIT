#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

signed main(){

    speed;  

    int test;
    cin >> test;
    int n;
    string s;
    while(test--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);

        int mark[10];
        memset(mark, 0, sizeof(mark));

        for (int i = 0; s[i]; ++i) {
            if(isdigit(s[i])) {
                mark[s[i] - '0'] = 1;
            }
        }

        for (int i = 0; i < 10; ++i) {
            if(mark[i]) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}