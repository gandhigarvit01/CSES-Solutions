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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a - 1].push_back({b - 1, c});
    }

    vector<ll> dis(n, INFLL);
    dis[0] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dis[u])
            continue;

        for (auto [v, wt] : adj[u])
        {
            if (d + wt < dis[v])
            {
                dis[v] = d + wt;
                pq.push({dis[v], v});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}