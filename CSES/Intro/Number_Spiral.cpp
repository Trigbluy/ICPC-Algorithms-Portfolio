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

void solve () {
    ll x, y, ans, sqr;
    cin >> y >> x;
    sqr = max(y,x);
    ans = (sqr-1)*(sqr-1);
    if (sqr%2) {
        ans += x;
        if (x == sqr)
            ans += sqr - y;
    }
    else {
        ans += y;
        if (y == sqr)
            ans += sqr - x;
    }
    cout << ans << endl;
}

int32_t main () {
    fastio;
    int n_c = 1;
    cin >> n_c;
    while (n_c--)
        solve();

    return 0;
}