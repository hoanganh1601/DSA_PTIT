#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n;
int a[12];
int visited[12];

void display() {
    for (int i = 1; i <= n; ++i) cout << a[i];
    cout << endl;
}

void Try(int i) {
    for (int j = 1; j <= n; ++j) {
        if(!visited[j]) {
            if(i >= 2 && abs(a[i - 1] - j) == 1) continue;

            visited[j] = 1;
            a[i] = j;
            if(i == n) display();
            else Try(i + 1);
            
            visited[j] = 0;
        }
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--){
        cin >> n;
        if(n == 3) continue;
        else {
            Try(1);
        }
    }   

    return 0;
}