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
const int NMAX= 1e4+10;
ll cs[NMAX];
ll ches (ll n) {
    if (1 == n) return 0;
    if (cs[n]) return cs[n];
    cs[n] = cs[n-1] + 9*(n-1)*(n-1) - 22 + (2*n-1)*(n-1) +2*(n-5)*((n-1)*(n-1) - 4) - 2;
    return cs[n];
}
void solve () {
    ll n;
    cin >> n;
    cs[2]=6, cs[3]=28,cs[4] =96,cs[5]=252,cs[6]=550;

    for (int i = 1; i <= n; i++) {
        cout << ches(i) << endl;
    }
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();

    return 0;
}