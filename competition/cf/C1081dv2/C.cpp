#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fin(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
#define f first
#define s second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

// int t;
// void build_seg(vi& arr, vi& sg, ll n, int l = 0, int r = 0, int ind = 0){
//     if (!l)
//         l = 1, r = n, ind = 1;
//     if (l == r){
//         sg[ind] = arr[l];
//         cout << l << " in " << ind << " = " << sg[ind] << endl;
//         return;
//     }
//     int m = (l+r)/2;
//     build_seg(arr,sg,n,l,m,2*ind);
//     build_seg(arr,sg,n,m+1,r,2*ind+1);
//     sg[ind] = max(sg[2*ind], sg[2*ind+1]);
//     // cout << "## " << sg[2*ind] << " " << sg[2*ind+1] << endl;
//     cout << l << " to " << r << " in " << ind << " = " << sg[ind] << endl;
// }

// ll mx(vi& sg, int n, int lq, int rq, int l = 0, int r = 0, int ind = 0) {
//     if (!l)
//         l = 1, r = n, ind = 1;
//     if (l <= lq && rq <= r)
//         return sg[ind];
//     int m = (l+r)/2;
//     ll ans = 0;
//     if (m >=lq)
//         ans = max(ans, mx(sg,n,lq,rq,l,m,2*ind));
//     if (m+1<=rq)
//         ans = max(ans, mx(sg,n,lq,rq,m+1,r,2*ind+1));
//     return ans;
// }

void solve () {
    ll n, h ,k;
    cin >> n >> h >> k;

    vi arr(n+1), sum(n+1);
    fin(i,1,n+1){
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
    if (h == 1){
        cout << 1 << endl;
        return;
    }
    
    ll lf = h%sum[n];
    if (!lf){
        cout << (n+k)*(h/sum[n]) - k << endl;
        return;
    }

    vi mx(n+1), mn(n+1);
    mn[1] = arr[1];
    fin(i,2,n+1)
        mn[i] = min(mn[i-1], arr[i]);
    mx[n] = arr[n];
    fin(i,1,n)
        mx[n-i] = max(mx[n-i+1], arr[n-i]);
    fin(i,1,n+1){
        if ((sum[i] >= lf) || (sum[i] + (mx[i+1]-mn[i]) >= lf)){
            cout << (n+k)*(h/sum[n]) + i << endl;
            return;
        }
    }

}

int main () {
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}