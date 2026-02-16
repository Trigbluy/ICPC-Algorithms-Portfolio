#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int NMAX = 4e5;
const ll M = 1e9+7;
ll dp[NMAX];

void solve() {
    int n, k, a, b;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        if(a == b)
            n -= 1;
        else
            n -= 2;
    }
    cout << dp[n] << endl;
}

void precalc() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= 3e5 + 100; i++)
        dp[i] = (dp[i-1] + (2*(i-1)*dp[i-2]) % M) % M;
}

int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    precalc();
    while(nt--)
        solve();
    return 0;
}