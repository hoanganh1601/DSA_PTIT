#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

string s, x;
char c[] = {'+', '-', '*', '/'};
bool ok = false;

bool checkValid() {
    int a = (x[0] - '0') * 10 + (x[1] - '0');
    int b = (x[5] - '0') * 10 + (x[6] - '0');
    int c = (x[10] - '0') * 10 + (x[11] - '0');
    
    if(x[3] == '+') return a + b == c;
    else if(x[3] == '-') return a - b == c;
    else if(x[3] == '*') return a * b == c;
    else {
        return a / b == c;
    }
}

void Try(int i) {
    if(ok) return;

    if(i == s.size()) {
        if(checkValid()) {
            ok = true;
            cout << x << endl;
        }
        return;
    }

    // Không phải dấu hỏi chấm (quay lui tiếp)
    if(s[i] != '?') Try(i + 1);
    
    else if(i == 3) {
        for (int j = 0; j < 4; ++j) {
            x[i] = c[j];
            Try(i + 1);
        }
    }

    else{
        for (int j = 0; j <= 9; ++j) {
            if(j == 0) {
                if(i == 0 || i == 5 || i == 10) continue;
            }

            x[i] = j + '0';
            Try(i + 1);
        }
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    cin.ignore();

    while(test--) {
        getline(cin, s);
        x = s;
        Try(0);

        if(!ok) cout << "WRONG PROBLEM!" << endl;
        ok = false; 
    }   

    return 0;
}