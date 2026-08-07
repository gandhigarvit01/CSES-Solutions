#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int, int>>;

const int INF = 1e9;
const ll INFLL = 1e18;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void printpath(int u, vector<int>& parent){
    vector<int> path;
    int nodes = 0;
    while(u!=-1){
        path.push_back(u);
        u = parent[u];
        nodes++;
    }
    cout << nodes << '\n';
    int m = path.size();
    for(int i=m-1; i>=0; i--){
        cout << path[i]+1 << " ";
    }
}

bool bfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent){
    int n = adj.size();
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == n-1){
            return true;
        }
        for(int v : adj[node]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = node;
                q.push(v);
            }
        }
    }
    return false;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    bool ans = bfs(0, adj, visited, parent);
    if(!ans){
        cout << "IMPOSSIBLE";
    }
    else{
        printpath(n-1, parent);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}