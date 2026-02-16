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
vi primes;

ll bpow (ll a, ll b) {
    if (b == 1) return a % M;
    if (b%2) return (a * bpow((a*a) % M, b/2)) % M;
    return bpow((a*a) % M, b/2);
}

ll fat (ll n) {
    if (n == 0) return 1;
    return (fat(n-1)*n)%M;
}

ll inv (ll n) {
    cout << "Inverso de " << n << " = " << bpow(n, M-2) << endl;
    return bpow(n, M-2);
}
ll bino (ll n, ll k) {
    cout << "Bin " << n << " escolhe " << k << " = " << (((fat(n)*inv(fat(k))) % M) * inv(fat(n-k))) % M <<  endl;
    if (n < k) return 0;
    return (((fat(n)*inv(fat(k))) % M) * inv(fat(n-k))) % M;
}

void solve () {
    ll t, k, ans, mpi = 1, np;
    cin >> t >> k;
    primes.pb(2);
    for (int i = 3; i <= t; i+=2){
        bool isp = true;
        for (ll a : primes) {
            if (i%a == 0) {
                isp = false;
                break;
            }
        }
        if(isp)
            primes.pb(i);
    }

    for (int i = 0; i < primes.size(); i++) {
        mpi = (mpi*primes[i]) % M;
    }
    cout << (np = primes.size() - 1) << ' ' << mpi << endl;
    ans = (bino (np, k - 1) * inv(fat(t))) % M;
    cout << ans << endl;
}


int main() {
    fastio;
    solve();
    return 0;
}