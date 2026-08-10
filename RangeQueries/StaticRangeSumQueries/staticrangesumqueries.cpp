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

void build(vector<ll>& seg, vector<int>& arr, int i, int l, int r){
    if(l==r){
        seg[i] = arr[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(seg, arr, 2*i+1, l, mid);
    build(seg, arr, 2*i+2, mid+1, r);
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

long long query(vector<ll>& seg, int i, int l, int r, int a, int b){
    if(a>r || b<l) return 0;
    if(l>=a && r<=b) return seg[i];
    int mid = l + (r-l)/2;
    return query(seg, 2*i+1, l, mid, a, b) + query(seg, 2*i+2, mid+1, r, a, b);
}

void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // make segment tree
    vector<ll> seg(4*n);
    build(seg, arr, 0, 0, n-1);
    // solve queries
    for(int i=0; i<q; i++){
        int a,b;
        cin >> a >> b;
        ll ans = query(seg, 0, 0, n-1, a-1, b-1);
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