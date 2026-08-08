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

ll target;

void findsubsets(vector<ll>& arr1, vector<ll>& arr2){
    int n = arr1.size();
    ll ans = 0;
    for(int i=0; i<n; i++){
        ll rem = target - arr1[i];
        ll count = upper_bound(arr2.begin(), arr2.end(), rem) - lower_bound(arr2.begin(), arr2.end(), rem);
        ans += count;
    }
    cout << ans;
    return;
}

void findsubsetsum(vector<ll>& arr, vector<ll>& arr1){
    int n = arr.size();
    for(int mask=0; mask<(1<<n); mask++){
        ll sum = 0;
        for(int i=0; i<n; i++){
            if((mask & (1<<i)) != 0){
                sum += arr[i];
            }
        }
        arr1.push_back(sum);
    }
}

void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    target = x;
    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // MITM as n<=40 , so 2^n will be too large, but 2^n/2 will work for us.
    vector<ll> arr1, arr2;
    int half = n/2;
    for(int i=0; i<half; i++){
        arr1.push_back(arr[i]);
    }
    for(int i=half; i<n; i++){
        arr2.push_back(arr[i]);
    }
    vector<ll> subsetsum1;
    vector<ll> subsetsum2;
    findsubsetsum(arr1, subsetsum1);
    findsubsetsum(arr2, subsetsum2);
    sort(subsetsum2.begin(), subsetsum2.end());
    findsubsets(subsetsum1, subsetsum2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}