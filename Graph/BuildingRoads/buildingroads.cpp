#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v, visited, adj);
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> hq;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            hq.push_back(i);
            dfs(i, visited, adj);
        }
    }
    int roads = hq.size() - 1;
    cout << roads << '\n';  // print number of roads
    // print k roads one by one
    for(int i=1; i<=roads; i++){
        cout << hq[i-1]+1 << " " << hq[i]+1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}