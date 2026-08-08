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

void floyd(int n, vector<vector<ll>> &adj)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] != INFLL && adj[k][j] != INFLL && adj[i][k] + adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> adj(n, vector<ll>(n, INFLL));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if(c < adj[a-1][b-1]){
            adj[a - 1][b - 1] = c;
            adj[b - 1][a - 1] = c;
        }
    }
    for (int i = 0; i < n; i++)
        adj[i][i] = 0;
    // floyd warshall
    floyd(n, adj);
    // queries
    for(int i=0; i<q; i++){
        int a,b;
        cin >> a >> b;
        cout << (adj[a-1][b-1]==INFLL? -1 : adj[a-1][b-1]) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}