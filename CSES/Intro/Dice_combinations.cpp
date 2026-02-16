#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define int ll
const int NMAX = 1e6+10;
const int M = 1e9+7;
using namespace std;

ll poss [NMAX];

int n;
void solve () {
    cin >> n;
    poss[0] = 1;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        for (int j = 1; j <= 6; j++)
            if (i-j >= 0)
                sum += poss[i-j] % M;
        poss[i] = sum % M;
    }

    cout << poss[n] % M << endl;
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;

    solve();

    return 0;
}