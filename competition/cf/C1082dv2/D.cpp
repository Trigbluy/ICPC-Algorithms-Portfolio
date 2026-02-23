#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fin(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
#define f first
#define s second
#define endl '\n'
#define int long long
const int NMAX = 3e5+3;
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve () {
    int n, k;
    cin >> n >> k;
    if (2*n-1 < k || k < n) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int l = 1, r = 1;
    if (k != n){
        cout << l << ' ';
        l++;
        cout << l << ' ';
        l++;
        k--;
    }
    k-=n;
    while(k > 0 && l <= n){
        cout << l << ' ';
        l++;
        cout << r << ' ';
        r++;
        k--;
    }
    while (l > r && r<=n){
        cout << r << ' ';
        r++;
    }
    while(l <= n){
        cout << l << ' ';
        cout << l << ' ';
        l++;
    }
    cout << endl;
}

int32_t main () {
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}