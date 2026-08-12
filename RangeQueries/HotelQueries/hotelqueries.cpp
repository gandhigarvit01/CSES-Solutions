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
vector<int> seg;

void build(int i, int l, int r){
    if(l==r){
        seg[i] = arr[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid+1, r);
    seg[i] = max(seg[2*i+1], seg[2*i+2]);
}

int query(int i, int l, int r, int val){
    if(l==r){
        if(seg[i] >= val) return l;
        return -1;
    }
    if(seg[i] < val) return -1;
    int mid = l + (r-l)/2;
    int res = query(2*i+1, l, mid, val);
    if(res!=-1) return res;
    return query(2*i+2, mid+1, r, val);
}

void update(int i, int l, int r, int idx, int val){
    if(l==r){
        seg[i] -= val;
        return;
    }
    int mid = l + (r-l)/2;
    if(idx<=mid) update(2*i+1, l, mid, idx, val);
    else update(2*i+2, mid+1, r, idx, val);
    seg[i] = max(seg[2*i+1], seg[2*i+2]);
}

void solve()
{
    int n,m;
    cin >> n >> m;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    seg.resize(4*n);
    // build tree
    build(0, 0, n-1);
    // q queries-
    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        int idx = query(0, 0, n-1, k);
        cout << idx+1 << " ";
        if(idx!=-1) update(0, 0, n-1, idx, k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}