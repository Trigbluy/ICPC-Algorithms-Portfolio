#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define endl '\n'
using namespace std;
const int NMAX = 2e5 + 10;

void solve () {
    int n, m;
    cin >> n >> m;
    vi vb;
    vii va;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        va.pb({a,i});
    }
    for (int i = 0; i < m; i++) {
        cin >> b;
        vb.pb(b);
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int ia = 0, ja = n-1, ib = 0, jb = m -1;
    ll ans = 0;

    while (ia <= ja) {
        if (abs(va[ia].ff - vb[jb]) >= abs(va[ja].ff - vb[ib])) {
            ans += abs(va[ia].ff - vb[jb]);
            ia++;
            jb--;
        }
        else {
            ans += abs(va[ja].ff - vb[ib]);
            ja--;
            ib++;
        }
    }

    cout << ans << endl;

}

int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}