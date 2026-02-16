#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long double ld;
typedef long long ll;
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
using namespace std;
map <ll, ll> crivo;
ll resp[2000], nnodes[2000];
vi prs[2000];
vll primes;

void solve () {
    int m, n, k;
    cin >> m >> n >> k;
    ll a, b, c;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        nnodes[i] = c;
    }
    for (int i = 1; i <= k; i++) {
        cin >> a >> b >> c;
        prs[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(prs[i].begin(), prs[i].end());
    }

    cout << resp[1];
    for (int i = 2; i <= m; i++) {
        cout << ' ' << resp[i];
    }
    cout << endl;
}

int main () {
    fastio;
    solve();
    return 0;
}