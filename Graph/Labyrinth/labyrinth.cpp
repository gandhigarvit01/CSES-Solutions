#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
using pii = pair<int, int>;
 
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
 
void path(int i, int j, vector<vector<pii>> &parent, vector<vector<char>> &adj, int len)
{
    string ans = "";
    while (adj[i][j] != 'A')
    {
        pii p = parent[i][j];
        int n_i = p.first;
        int n_j = p.second;
        if (n_i == i)
        {
            if (n_j == j - 1)
                ans.push_back('R');
            else
                ans.push_back('L');
        }
        else
        {
            if (n_i == i - 1)
                ans.push_back('D');
            else
                ans.push_back('U');
        }
        len++;
        i = n_i;
        j = n_j;
    }
    reverse(ans.begin(), ans.end());
    cout << len << '\n';
    cout << ans << '\n';
}
 
bool bfs(int i, int j, vector<vector<pii>> &parent, vector<vector<bool>> &visited, vector<vector<char>> &adj)
{
    int n = adj.size();
    int m = adj[0].size();
    queue<pii> q;
    q.push({i, j});
    visited[i][j] = true;
    while (!q.empty())
    {
        pii p = q.front();
        q.pop();
        int u = p.first;
        int v = p.second;
        if (adj[u][v] == 'B')
            return true;
        for (int k = 0; k < 4; k++)
        {
            int n_u = u + dx[k];
            int n_v = v + dy[k];
            if (n_u >= 0 && n_u < n && n_v >= 0 && n_v < m && !visited[n_u][n_v] && (adj[n_u][n_v] == '.' || adj[n_u][n_v] == 'B'))
            {
                visited[n_u][n_v] = true;
                parent[n_u][n_v] = {u, v};
                q.push({n_u, n_v});
            }
        }
    }
    return false;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pii>> parent(n, vector<pii>(m, {-1, -1}));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == 'A')
            {
                bool ans = bfs(i, j, parent, visited, adj);
                if (!ans)
                {
                    cout << "NO";
                    return;
                }
                else
                {
                    cout << "YES\n";
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            if (adj[i][j] == 'B')
                            {
                                path(i, j, parent, adj, 0);
                            }
                        }
                    }
                    return;
                }
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}