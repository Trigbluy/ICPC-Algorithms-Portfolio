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
const ll M = 1e9+7;
const int NMAX = 1e5+100;
vi graph [NMAX];
int dp[NMAX][101];
void solve () {
    int n, m, nc;
    cin >> n >> m >> nc;
    int a,b,c;
    vector<pair<ii,int>> edges;
    fin(i,0,m){
        cin >> a >> b >> c;
        edges.pb({{a,b},c});
    }
    fin(i,1,nc+1)
        dp[1][i] = i;
    fin(i,1,nc+1)
        for (auto e : edges){
            a = e.f.f, b = e.f.s, c = e.s;
            if (i-c >= 0)
                dp[b][i] = (dp[a][i-c] + dp[b][i])%M;
        }
    ll ans = 0;
    fin (i,1,n+1)
        ans = (ans + dp[i][nc])%M;
    cout << ans << endl;
}
int32_t main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}