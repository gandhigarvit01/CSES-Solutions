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

vector<int> arr;
vector<ll> seg;

void build(int i, int l, int r){
    if(l==r){
        seg[i] = arr[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid+1, r);
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

void update(int idx, int val, int i, int l, int r){
    if(l==r){
        seg[i] = val;
        return;
    }
    int mid = l + (r-l)/2;
    if(idx <= mid){
        update(idx, val, 2*i+1, l, mid);
    }
    else{
        update(idx, val, 2*i+2, mid+1, r);
    }
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

ll query(int i, int l, int r, int a, int b){
    if(b<l || a>r) return 0;
    if(l>=a && r<=b) return seg[i];
    int mid = l + (r-l)/2;
    return query(2*i+1, l, mid, a, b) + query(2*i+2, mid+1, r, a, b);
}

void solve()
{
    int n,q;
    cin >> n >> q; 
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // build segtree
    seg.resize(4*n);
    build(0, 0, n-1);
    // queries;
    for(int i=0; i<q; i++){
        int k,a,b;
        cin >> k >> a >> b;
        if(k==1){
            update(a-1, b, 0, 0, n-1);
        }
        else{
            ll ans = query(0, 0, n-1, a-1, b-1);
            cout << ans << '\n'; 
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}