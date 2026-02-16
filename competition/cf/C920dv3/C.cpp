#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ll long long
using namespace std;

void solve () {
    ll a,b,f,n;
    cin >> n >> f >> a >> b;
    ll ma = 0, mn;
    for (int i = 0 ; i < n; i++) {
        cin >> mn;
        f -= min (a*(mn - ma), b);
        ma = mn;
    }
    if (f <= 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}