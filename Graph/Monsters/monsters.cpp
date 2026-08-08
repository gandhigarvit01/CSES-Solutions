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

int Ai, Aj;

void print(int i, int j, vector<vector<pii>>& parent){
    int k = 0;
    string path = "";
    while(i!=Ai || j!=Aj){
        auto [par_i,par_j] = parent[i][j];
        if(par_i==i){
            if(par_j==j-1) path.push_back('R');
            else path.push_back('L');
        }
        else{
            if(par_i==i-1) path.push_back('D');
            else path.push_back('U');
        }
        i = par_i;
        j = par_j;
        k++;
    }
    cout << "YES" << '\n' << k << '\n';
    for(int l=path.size()-1; l>=0; l--){
        cout << path[l];
    }
}

pair<bool,pair<int,int>> possible(vector<vector<char>> &adj, vector<vector<pair<int, int>>> &parent, vector<vector<bool>> &visited)
{
    int n = adj.size();
    int m = adj[0].size();
    queue<pii> q1;
    queue<pii> q2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == 'M')
            {
                q2.push({i, j});
            }
            else if (adj[i][j] == 'A')
            {
                Ai = i;
                Aj = j;
                q1.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    while (!q1.empty())
    {
        int l = q2.size();
        while (l)
        {
            pii p = q2.front();
            q2.pop();
            int i = p.first;
            int j = p.second;
            for (int k = 0; k < 4; k++)
            {
                int n_i = i + dx[k];
                int n_j = j + dy[k];
                if (n_i >= 0 && n_i < n && n_j >= 0 && n_j < m && (adj[n_i][n_j] == '.' || adj[n_i][n_j] == 'A'))
                {
                    adj[n_i][n_j] = 'M';
                    q2.push({n_i, n_j});
                }
            }
            l--;
        }
        l = q1.size();
        while (l)
        {
            pii p = q1.front();
            q1.pop();
            int i = p.first;
            int j = p.second;
            if(i==0 || i==n-1 || j==0 || j==m-1){
                return {true, {i,j}};
            }
            for (int k = 0; k < 4; k++)
            {
                int n_i = i + dx[k];
                int n_j = j + dy[k];
                if (n_i >= 0 && n_i < n && n_j >= 0 && n_j < m && adj[n_i][n_j] == '.' && !visited[n_i][n_j])
                {
                    visited[n_i][n_j] = true;
                    parent[n_i][n_j] = {i,j};
                    q1.push({n_i, n_j});
                }
            }
            l--;
        }
    }
    return {false, {-1,-1}};
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    auto ans = possible(adj, parent, visited);
    bool res = ans.first;
    if(!res){
        cout << "NO";
    }
    else{
        print(ans.second.first, ans.second.second, parent);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}