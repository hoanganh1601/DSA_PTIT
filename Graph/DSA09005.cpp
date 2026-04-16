#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int v, e, start;

void init() {
    cin >> v >> e >> start;
    for (int i = 1; i <= v; ++i) {
        adj[i].clear();
        visited[i] = false;
    }  
}

void BFS(int start) {

    queue<int> q; 
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int x : adj[u]) {
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;   
    while(test--) {
        
        init();

        for (int i = 1; i <= e; ++i) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }   

        BFS(start);
        cout << endl;
    }

    return 0;
}