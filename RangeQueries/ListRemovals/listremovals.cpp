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
        seg[i] = 1;
        return;
    }
    int mid = l + (r-l)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid+1, r);
    seg[i] = seg[2*i+1] + seg[2*i+2];
}

int query(int i, int l, int r, int k){
    if(seg[i] < k) return -1;
    if(l==r){
        if(seg[i]==1){
            seg[i] = 0;
            return l;
        }
        return -1;
    }
    int mid = l + (r-l)/2;
    int res = query(2*i+1, l, mid, k);
    if(res==-1) res = query(2*i+2, mid+1, r, k-seg[2*i+1]);
    seg[i] = seg[2*i+1] + seg[2*i+2];
    return res;
}

void solve()
{
    int n;
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    seg.resize(4*n);
    // build segtree
    build(0,0,n-1);
    // queries;
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        int idx = query(0, 0, n-1, k);
        cout << arr[idx] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}