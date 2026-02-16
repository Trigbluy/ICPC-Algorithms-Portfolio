#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
typedef long double ld;
typedef long long ll;
#define ii pair<int,int>
#define vi vector<ll>
#define pb push_back
#define f first
#define s second
using namespace std;
const int INF  = numeric_limits <int> :: max();
const int NMAX = 5e3 + 100;
const ll  M    = 998244353;
ll fat[NMAX], inv[NMAX], ifat[NMAX];

ll bino (ll n, ll k) {
    if (n == k || k == 0) return 1;
    if (k > n || k < 0) return 0;
    return (((fat[n] * ifat[k]) % M) * ifat[n - k]) % M;
}

ll dp (int i, int j) {
    if (j > i) return 0;
    if ((i + j) % 2) return 0;
    return bino (i, (i+j) / 2) - bino (i, 1 + (i+j)/2);
}

ll bpow (ll a, ll b) {
    if (b == 1) return a%M;
    if (b%2) return (a*bpow(a*a % M, b/2)) % M;
    return bpow(a*a % M, b/2);
}

void solve () {
    fat[0] = 1;
    for (int i = 1; i <= 5e3 + 10; i++)
        fat[i] = (i*fat[i-1]) % M;
    inv[1] = 1;
    for(ll a = 2; a <= 5e3+10; ++a)
        inv[a] = (M - (((long long)(M/a) * inv[M%a]) % M)) % M;
    ifat[0] = 1;
    for (int i = 1; i <= 5e3 + 10; i++)
        ifat[i] = (inv[i]*ifat[i-1]) % M;
    for (int i = 1; i <= 5e3 + 10; i++) {
        if (inv[i] != bpow(i, M-2)) {
            
        }
    }
}


int main() {
    fastio;
    solve();
    return 0;
}