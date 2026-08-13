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

int mod = 1e9+7;

void solve()
{
    int n;
    cin >> n;
    vector<long long> dp(n+1);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        long long ans = 0;
        for(int j=1; j<=6; j++){
            if(i-j>=0) ans = (ans + dp[i-j]) % mod; 
        }
        dp[i] = ans;
    }

    cout << dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}