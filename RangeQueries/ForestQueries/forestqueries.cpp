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

vector<vector<char>> arr;
vvi prefix;

void build(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i-1>=0) prefix[i][j] += prefix[i-1][j];
            if(j-1>=0) prefix[i][j] += prefix[i][j-1];
            if(i-1>=0 && j-1>=0) prefix[i][j] -= prefix[i-1][j-1];
            if(arr[i][j]=='*') prefix[i][j] += 1;
        }
    }
}

int query(int x1, int y1, int x2, int y2){
    int res = 0;
    res += prefix[x2][y2];
    if(x1-1>=0 && y1-1>=0) res += prefix[x1-1][y1-1];
    if(y1-1>=0) res -= prefix[x2][y1-1];
    if(x1-1>=0) res -= prefix[x1-1][y2];
    return res;
}

void solve()
{
    int n,q;
    cin >> n >> q;
    arr.resize(n, vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    // build prefix array;
    prefix.resize(n, vector<int>(n));
    build(n);

    // process q queries
    for(int i=0; i<q; i++){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = query(x1-1,y1-1,x2-1,y2-1);
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}