#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define fin(i,a,b) for (int i = a; i < (int) b; i++)
#define int ll
#define pb push_back
#define f first
#define s second
// #define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
const ll INF = 1e15;
const int NMAX = 5e2 + 100;
ll adj[NMAX][NMAX];
void solve () {
    int n, m, q;
    cin >> n >> m >> q;
    int a, b ,c;
    fin(i,1,n+1)
        fin(j,1,n+1)
            adj[i][j] = INF;
    fin (i,1,n+1)
        adj[i][i] = 0;
    fin(i,0,m){
        cin >> a >> b >> c;
        adj[a][b] = min(c, adj[a][b]);
        adj[b][a] = min(c, adj[b][a]);
    }
    fin(k,1,n+1)
        fin(i,1,n+1)
            fin(j,1,n+1)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    while(q--){
        cin >> a >> b;
        cout << ((adj[a][b] == INF)?-1:adj[a][b]) << endl;
    }
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}
