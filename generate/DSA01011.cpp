#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int stt;
string res;

void generate() {
    int i = res.size() - 2;
    while(i >= 0 && res[i] >= res[i + 1]) --i;
    if(i == -1) {
        cout << "BIGGEST" << endl;
    }
    else {
        int j = res.size() - 1;
        while(res[j] <= res[i]) --j;
        swap(res[i], res[j]);
        int left = i + 1, right = res.size() - 1;
        while(left < right) {
            swap(res[left], res[right]);
            ++left; --right;
        }

        cout << res << endl;
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> stt >> res;
        cout << stt << " ";
        generate();
    }   

    return 0;
}