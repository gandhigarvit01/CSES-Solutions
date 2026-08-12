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
vector<ll> lazy;

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

void update(int i, int l, int r, int ql, int qr, ll val){
    if(lazy[i]!=0){
        seg[i] += (1ll*lazy[i])*(r-l+1);
        if(l!=r){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(r<ql || l>qr) return;
    if(l>=ql && r<=qr){
        seg[i] += (1ll*val)*(r-l+1);
        if(l!=r){
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    } 
    int mid = l + (r-l)/2;
    update(2*i+1, l, mid, ql, qr, val);
    update(2*i+2, mid+1, r, ql, qr, val);
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

ll query(int i, int l, int r, int idx){
    if(lazy[i]!=0){
        seg[i] += (1ll*lazy[i])*(r-l+1);
        if(l!=r){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(l==r) return seg[i];
    int mid = l + (r-l)/2;
    if(idx<=mid){
        return query(2*i+1, l, mid, idx);
    }
    return query(2*i+2, mid+1, r, idx);
}

void solve()
{
    int n,q;
    cin >> n >> q;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    seg.resize(4*n);
    lazy.resize(4*n,0);
    // build segtree
    build(0, 0, n-1);
    // process queries
    for(int i=0; i<q; i++){
        int k,a,b,val;
        cin >> k;
        if(k==1) cin >> a >> b >> val;
        else cin >> a;
        if(k==1){
            update(0, 0, n-1, a-1, b-1, val);
        }
        else{
            ll res = query(0, 0, n-1, a-1);
            cout << res << '\n';
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