#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define fin(i,a,b) for (int i = a; i < (int) b; i++)
#define pb push_back
#define f first
#define s second
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int NMAX = 1e6 + 100;
const ll M = 1e9+7;
ll dp_[NMAX], suf[NMAX];
void solve () {
    ll k;
    cin >> k;
    dp_[0] = dp_[1] = 1; suf[1] = 2; suf[0] = 1;
    for (ll i = 2; i <= k; i++){
        dp_[i] = ((suf[i-1] - suf[i-i/2-1])%M+M)%M;
        suf[i] = (suf[i-1] + dp_[i])%M;
    }
    cout << dp_[k] << endl;
}
int32_t main () {
    // fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}