#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ff first
#define ss second
#define ll long long
#define int ll
#define ld long double
#define ull unsigned ll
using namespace std;

const int NMAX = 5e2 + 10;

void solve () {
    ll n, m, k;
    cin >> n >> m >> k;

    ull l = 1, r = numeric_limits<ull> :: max(), t;
    ull mmc = n*m/__gcd(n,m);
    while (l < r) {
        t = (l/2) + (r/2) + ((l%2 + r%2)/2);
        if ((t/n -t/(mmc)) + (t/m - (t/(mmc))) <= k)
            l = t + 1;
        else
            r = t - 1;
    }

    while (((l)/n - (l)/(mmc)) + ((l)/m - (l)/(mmc)) >= k && l != 0)
        l--;
    if (((l+1)/n - (l+1)/(mmc)) + ((l+1)/m - (l+1)/(mmc)) == k)
        l++;

    cout << l << endl;
}

signed main () {
    fastio;
    int n_c = 1;
    while (n_c--) {
        solve();
    }
    return 0;
}