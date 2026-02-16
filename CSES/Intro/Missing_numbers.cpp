#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define int ll

using namespace std;

int n;

void solve () {
    cin >> n;
    ull sum = n*(n+1)/2;
    int aux;
    for (int i = 0 ; i < n - 1; i ++) {
        cin >> aux;
        sum -= aux;
    }
    cout << sum << endl;
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();

    return 0;
}