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

bool divide(int u, vector<int>& team, vector<vector<int>>& adj, int team_no){
    team[u] = team_no;
    for(int v : adj[u]){
        if(team[v]==team_no) return false;
        else if(team[v]==0){
            int new_team_no = team_no==1 ? 2 : 1;
            bool res = divide(v, team, adj, new_team_no);
            if(!res) return false;
        }
    }
    return true;
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
    vector<int> team(n, 0);
    for(int i=0; i<n; i++){
        if(team[i]==0){
            bool ans = divide(i, team, adj, 1);
            if(!ans){
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << team[i] << " ";
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}