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
    // cout << "binomial: (" << n << ' ' << k << " ) " << (((fat[n] * ifat[k]) % M) * ifat[n - k]) % M << endl;
    return (((fat[n] * ifat[k]) % M) * ifat[n - k]) % M;
}

ll dp (ll i, ll j) {
    if (j > i) return 0;
    if (i == j) return 1;
    if ((i + j) % 2) return 0;
    return (bino (i, (i+j) / 2) - bino (i, 1 + (i+j)/2) + M) % M;
}

void solve () {
    fat[0] = 1;
    for (ll i = 1; i <= 5e3 + 10; i++)
        fat[i] = (i*fat[i-1]) % M;
    inv[1] = 1;
    for(ll a = 2; a <= 5e3+10; ++a)
        inv[a] = (M - (((long long)(M/a) * inv[M%a]) % M)) % M;
    ifat[0] = 1;
    for (int i = 1; i <= 5e3 + 10; i++)
        ifat[i] = (inv[i]*ifat[i-1]) % M;

    ll n, m;
    cin >> n;
    string str;
    cin >> str;
    m = str.size();
    int fechando = 0, msf = 0;
    for (auto c : str) {
        if (c == ')') {
            fechando++;
            msf = max(msf, fechando);
        }
        else
            fechando--;
    }
    int abrindo = 0, msa = 0;
    for (auto c  = str.rbegin(); c != str.rend(); c++) {
        if ( *c == '(') {
            abrindo++;
            msa = max(msa, abrindo);
        }
        else 
            abrindo--;
    }
    ll ans = 0;
    // cout << msf << ' ' << msa << endl;
    for (int i = msf; i <= n-m; i++) {
        // cout << "( " << i << ", " << n-m-i << ") " << dp(i, msf) << " " << dp(n - m - i, msa) << endl;
        for (int j = msf; j <= i; j++) {
            // cout << "( " << i << ", " << j << ") " << dp(i, j) << " " << dp(n - m - i, msa + (j-msf)) << " <- (" << n - m - i << " " << msa + (j-msf)  << ")" << endl;
            ans = (ans + (dp(i, j) * dp(n - m - i, msa + (j-msf))) % M) % M;
        }
    }
    cout << ans << endl;
}


int main() {
    fastio;
    solve();
    return 0;
}