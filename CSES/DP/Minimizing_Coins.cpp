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
#define ii pair<int,int>
#define vii vector<ii>

using namespace std;
const int NMAX = 1e6 + 10;
set<int> coins;
int dp_[NMAX];
ll minimo (ll a, ll b) {
    if (a == -1 && b != -1)    return b + 1;
    if (b == -1)    return a;
    return min(a,b+1);
}
ll dp (int value) {
    if (value == 0)         return 0;
    if (value < 0)          return -1;
    if (dp_[value] != 0)    return dp_[value];

    int mn = -1;
    for (int v : coins)
        mn = minimo(mn, dp(value - v));
    dp_[value] = mn;
    return mn;
}

void solve () {
    int n, x, aux;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> aux;
        coins.insert(aux);
    }
    cout << dp(x) << endl;
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();

    return 0;
}