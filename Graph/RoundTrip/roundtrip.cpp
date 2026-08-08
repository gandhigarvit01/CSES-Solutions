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

bool cycle(int u, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& path, int parent){
    visited[u] = true;
    path.push_back(u);
    for(int v : adj[u]){
        if(visited[v]){
            if(v!=parent){
                path.push_back(v);
                return true;
            }
        }
        else{
            bool res = cycle(v, visited, adj, path, u);
            if(res) return true;
        }
    }
    path.pop_back();
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
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            vector<int> path;
            bool ans = cycle(i, visited, adj, path, -1);
            if(ans){
                // print;
                int len = path.size();
                int start = path[len-1];
                int j = len-2;
                while(path[j]!=start){
                    j--;
                }
                cout << len-j << '\n';
                for(; j<len; j++){
                    cout << path[j]+1 << " ";
                }
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}