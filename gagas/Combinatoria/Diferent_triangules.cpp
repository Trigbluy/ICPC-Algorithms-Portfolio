#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
const ll M = 1e9+7;
const int NMAX = 1e6+100;
const int maxval = NMAX;
ll fat[NMAX], inv[NMAX], invFat[NMAX];
void pre_calc() {
    inv[1] = 1, fat[0] = fat[1] = 1;
    invFat[1] = 1;
    for(int a = 2; a < maxval; ++a) {
        inv[a] = M - (long long)(M/a) * inv[M%a] % M;
        fat[a] = (fat[a-1]*a)%M;
        invFat[a] = (invFat[a-1]*inv[a])%M;
    }
}

ll comb (ll n, ll p) {
    cout << "Comb " << n << ' ' << p << ": " << (((fat[n]*invFat[p]) % M) * invFat[n-p]) % M << endl;
    return (((fat[n]*invFat[p]) % M) * invFat[n-p]) % M;
}

ll bpow (ll a, ll b) {
    if (!b) return 1LL;
    if (b%2)    return (a*bpow((a*a)%M, b/2))%M;
    return bpow((a*a)%M, b/2);
}

ll inve (ll a) {
    return bpow(a, M-2);
}

ll lcomb (ll n, ll p) {
    return( ((fat[n]*inve(fat[n-p]))%M) * inve(fat[p])) % M;
}

void solve() {
    ll n;
    cin >> n;
    ll n1 = !(n%3);
    ll n2 = (((n+1)/2 - 1)-(n+2-2*((n+1)/2)))/2 - n1;
    // ll n2 = 3;
    ll n3 = (((comb(n-1,2) - 3*comb(n-(n+1)/2, 2)) - n2) % M + M) % M;
    cout << n1 << ' ' << n2 << ' '<< n3 << endl;
    cout << ((n1 + n2 + n3) % M + M) % M << endl;

}
int main () {
    fastio;
    pre_calc();
    int nt = 1;
    // cin >> nt;
    while(nt--)
        solve();
    return 0;
}