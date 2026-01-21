#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

char c;
int n;
bool visited[50];
char res[50];

void display() {
    for (int i = 1; i <= n; ++i) cout << res[i];
    cout << endl;
}

bool check(char x){
    if(x == 'A' || x == 'E') return true;
    return false;
}

void Try(int i) {
    for (int j = 1; j <= n; ++j) {
        if(!visited[j] ) {
            if(i >= 3 && !check(res[i - 2]) && check(res[i - 1]) && !check('A' + j - 1)) continue;

            visited[j] = 1;
            res[i] = 'A' + j - 1;
            if(i == n) display();
            else Try(i + 1);

            visited[j] = 0;
        }
    }
}

signed main(){

    speed;  

    cin >> c;
    n = c - 'A' + 1;

    Try(1);

    return 0;
}