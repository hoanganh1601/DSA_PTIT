#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n, w;
vector<int> x, xopt; 
int fopt = -1;
vector<int> value, weight;

int curVal = 0, curWeight = 0;

void readData() {
    // freopen("data.in", "r", stdin);
    cin >> n >> w;
    x.resize(n); xopt.resize(n);
    value.resize(n); weight.resize(n);

    for (int i = 0; i < n; ++i) cin >> value[i];
    for (int i = 0; i < n; ++i) cin >> weight[i];
}

void Try(int i) {

    for (int j = 0; j <= 1; ++j) {
        x[i] = j;

        if(curWeight + x[i] * weight[i] <= w) {
            curVal += value[i] * x[i];
            curWeight += weight[i] * x[i];

            if(i == n - 1) {
                if(fopt < curVal) {
                    fopt = curVal;
                    for (int k = 0; k < n; ++k){
                        xopt[k] = x[k];
                    }
                }
            }
            else Try(i + 1);

            curVal -= value[i] * x[i];
            curWeight -= weight[i] * x[i];
        }
    }
}


signed main(){

    speed;  

    readData();
    Try(0);

    cout << fopt << endl;
    for (int x : xopt) {
        cout << x << " ";
    }

    return 0;
}