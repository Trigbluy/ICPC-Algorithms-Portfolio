#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
// #define int ll
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define endl '\n'
using namespace std;
typedef vector<ll> vll;
const int NMAX= 1e6+10;
const ll M = 1e9+7;
void solve () {
    set<ll> sums;
    sums.insert(0);
    ll n, a;
    cin >> n;
    for (int i = 0 ; i < n ; i ++){
        cin >> a;
        vll aux;
        for (ll b : sums)
            aux.pb(a+b);
        for (ll b : aux)
            sums.insert(b);
    }
    ll sum = *sums.rbegin(), x = -10, y= -10;
    auto lb = lower_bound(sums.begin(), sums.end(), sum/2);
    auto up = upper_bound(sums.begin(), sums.end(), sum/2);
    if (lb != sums.end())   x = *lb;
    if (up != sums.end())   y = *up;
    cout << min (labs(sum - x - x), labs(sum - y - y)) << endl;
}
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();
 
    return 0;
}