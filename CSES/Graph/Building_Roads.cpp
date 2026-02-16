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
const int NMAX = 1e5 + 100;
vi graph[NMAX];
int marc[NMAX], dist[NMAX], pilha[NMAX];
void dfs (int v) {
    marc[v] = 1;
    fin(i,0,graph[v].size()){
        int viz = graph[v][i];
        if(!marc[viz])
            dfs(viz);
    }
}
void solve () {
    int n, m;
    cin >> n >> m;
    int a, b;
    fin(i,1,m+1){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vii ans;
    int last = -1;
    fin(i,1,n+1)
        if (!marc[i]){
            // cout << "dfs in " << i << endl;
            dfs(i);
            if(last != -1)
                ans.pb({i,last});
            last = i;
        }
    cout << ans.size() << endl;
    fin(i,0,ans.size())
        cout << ans[i].f << ' ' << ans[i].s << endl;
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}
