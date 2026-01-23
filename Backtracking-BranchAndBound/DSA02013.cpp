#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

#define MAX 1000005

int n, p, s;
bool isPrime[1000005];
vector<int> primes, res;
vector<vector<int>> listRes;
int len;

void sieve() {
    isPrime[0] = true;
    isPrime[1] = true;

    for (int i = 2; i < 1000005; ++i) {
        if(!isPrime[i]) primes.pb(i);
        
        for (int x : primes) {
            if(i * x > 1000005) break;
            isPrime[i * x] = true;
            if(i % x == 0) break;
        }
    }
}

// int cnt = 0;
void Try(int start, int curSum) {
    // ++cnt;
    // cout << curSum << " ";
    if(res.size() == n) {
        if(curSum == s) listRes.pb(res);
        return;
    }

    int shortage = n - res.size();

    // Đk dừng sớm: Nếu số lượng phần tử còn lại trong mảng primes không đủ để chọn
    // (len - 1) là chỉ số cuối cùng. (len - start) là số lượng phần tử từ start đến hết.
    if (len - start < shortage) return;
    
    for (int j = start; j <= len - shortage; ++j) {
        
        if(curSum + primes[j] > s) break;
        
        if(curSum + shortage * primes[j] > s) break;

        res.pb(primes[j]);
        Try(j + 1, curSum + primes[j]);
        res.pob();
    }
}

signed main(){

    speed;  

    sieve();

    int test;
    cin >> test;
    while(test--){
        cin >> n >> p >> s;
        if(p > s) cout << 0 << endl;
        else {
            vector<int>::iterator it = upper_bound(primes.begin(), primes.end(), p);
            if(it == primes.end()) cout << 0 << endl;
            else {
                int idx = (it - primes.begin());

                len = primes.size();
                // cout << len << endl;
                Try(idx, 0);    
                // cout << cnt << " ";

                cout << listRes.size() << endl;
                for (vector<int> x : listRes) {
                    for (int y : x) cout << y << " ";
                    cout << endl;
                }
            }

            listRes.clear();
        }
    }   

    return 0;
}