#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int NMAX = 1e6 + 10;
const ll M = 1e9 + 7;
ll fat[NMAX];
ll bpow (ll a, ll b) {
    if (!b) return 1;
    if (b%2) return (a*bpow((a*a)%M,b/2))%M;
    return bpow((a*a)%M,b/2);
}

ll comb (ll n, ll p) {
    return (fat[n] * bpow( (fat[n-p]*fat[p])%M, M-2)) % M;
}

void precalc () {
    fat[0] = 1;
    for (int i = 1; i < NMAX; i++) {
        fat[i] = (i*fat[i-1])%M;
    }
}
void solve () {
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for (int i = 0 ; i < k; i++) {
        if (i%2)
            ans = ((ans - comb(k, i)*bpow(k-i,n))%M + M)%M;
        else
            ans = (ans + comb(k, i) * bpow(k-i,n))%M;
    }
    cout << (comb(m,k)*ans ) % M << endl;
}
int main () {
    precalc();
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}