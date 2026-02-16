#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define int ll
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>

using namespace std;
const ll M = 1e9 + 7;

void solve () {
    vl coins, dp;
    ll n, x, c;
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> c;
        coins.pb(c);
    }
    dp.pb(1);
    for (int i = 1; i <= x; i++) {
        dp.pb(0);
        for(auto v : coins) {
            if (i >= v)
                dp[i] = (dp[i] + dp[i-v]) % M;
        }
    }
    cout << dp[x] << endl;
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();

    return 0;
}