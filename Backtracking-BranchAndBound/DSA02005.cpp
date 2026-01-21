#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

string res;
int n;
char x[12];
bool visited[12];

void display() {
    for (int i = 1; i <= n; ++i) cout << x[i];
    cout << " ";
}

void Try(int i) {
    for (int j = 1; j <= n; ++j) {
        if(!visited[j]) {
            visited[j] = true;
            x[i] = res[j];
            if(i == n) display();
            else Try(i + 1);

            visited[j] = false;
        }
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> res;
        n = res.size();
        res = "0" + res;
        Try(1);
        cout << endl;
    }

    return 0;
}