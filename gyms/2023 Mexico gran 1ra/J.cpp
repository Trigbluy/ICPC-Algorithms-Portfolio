#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
typedef long long ll;
using namespace std;

const int NMAX = 1e6 + 10;
const ll  M    = 1e9 + 7;
ll pre[NMAX], pre_sqr[NMAX];
int main () {
    fastio;
    ll n, q, aux;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> aux;
        pre[i] = (aux + pre[i-1])%M;
        pre_sqr[i] = (aux*aux % M + pre_sqr[i-1])%M;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        ll S1   = ((pre[r] - pre[l-1])% M + M) % M;
        ll T2   = ((pre_sqr[r] - pre_sqr[l-1])%M + M)%M;
        ll inv_2 = 500000004LL;

        ll resp = ((((S1*S1 % M - T2) % M + M) % M) * inv_2) % M;
        cout << resp << endl;
    }

    return 0;
}