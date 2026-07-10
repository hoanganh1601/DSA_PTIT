#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

vector<bool> isPrime(10000, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < 10000; ++i) {
        if(isPrime[i]) {
            for (int j = i * i; j < 10000; j += i) isPrime[j] = false;
        }
    }
}

int bfs(string s, string t) {
    if(s == t) return 0;

    queue<pair<string, int>> q;
    vector<bool> vs(10000, false);

    q.push({s, 0});
    vs[stoi(s)] = true;

    while(!q.empty()) {
        string curr = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            char tmp = curr[i];
            for (char c = '0'; c <= '9'; ++c) {
                if(i == 0 && c == '0') continue;

                if(c != tmp) {
                    curr[i] = c;
                    int num = stoi(curr);

                    if(isPrime[num] && !vs[num]) {
                        vs[num] = true;
                        if(curr == t) return steps + 1;
                        q.push({curr, steps + 1});
                    }
                }
            }
            curr[i] = tmp;
        }
    }

    return -1;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();

    int test; cin >> test;
    while(test--) {
        string s, t;
        cin >> s >> t;
        cout << bfs(s, t) << endl;
    }

    return 0;
}