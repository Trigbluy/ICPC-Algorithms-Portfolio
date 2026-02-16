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
int marc[NMAX];
int n, m, na;
bool dfs (int v, int b = 1){
    marc[v]=1+b; na++;
    fin(i,0,graph[v].size()){
        int viz = graph[v][i];
        if(!marc[viz]){
            if(!dfs(viz, !b))
                return false;
        }
        else
            if (marc[viz] == 1+b)
                return false;
    }
    return true;
}
void solve () {
    cin >> n >> m;
    int a,b;
    fin(i,0,m){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bool ok = true;
    fin(i,1,n+1)
        if(!marc[i])
            ok = ok && dfs(i);
    if(!ok)
        cout << "IMPOSSIBLE\n";
    else {
        cout << 2;
        fin(i,2,n+1)
            cout << ' ' << marc[i];
        cout << endl;
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
