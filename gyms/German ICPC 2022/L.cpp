#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define vi vector<ll>
#define pb push_back
using namespace std;
void solve () {
    int n, k;
}
void precalc () {
    ll nmax = 10 + 1e5;
    vi primes;
    primes.pb(2);
    for (ll i = 3; i < nmax/2; i++) {
        bool pr = true;
        for (ll p : primes) {
            if (i%p == 0) {
                pr = false;
                break;
            }
        }
        if (pr)
            primes.pb(i);
    }
    cout << primes.size() << endl;
}
int main () {
    fastio;
    precalc();
    int nt = 1;
    cin >> nt;
    while (nt--)
        solve();
    return 0;
}