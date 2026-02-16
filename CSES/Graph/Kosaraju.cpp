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
const ll INF = numeric_limits<ll> :: max();
const ll NINF = -(INF-1);
const int NMAX = 2e5+100;
const ll M = 1e9+7;
vi graph[NMAX][2], cgraph[NMAX];
int marc[NMAX], comp[NMAX], compSz[NMAX], coin[NMAX], coinComp[NMAX];
int pilha[NMAX];
ll dp_[NMAX];
int n, m, c, p;
void dfs_K(int v, int ind){
    marc[v] = !ind;
    if(ind){
        comp[v] = c;
        compSz[c]++;
    }
    fin(i,0,graph[v][ind].size()){
        int viz = graph[v][ind][i];
        if(marc[viz] == ind)
            dfs_K(viz,ind);
    }
    if (!ind)
        pilha[++p] = v;
}
void Kosaraju () {
    c = 0, p = -1;
    fin(i,1,n+1)
        if (!marc[i])
            dfs_K(i,0);
    while(p!=-1){   
        int v = pilha[p--];
        if(marc[v]){
            c++;
            dfs_K(v,1);
        }
    }
    fin(v,1,n+1)
        fin(i,0,graph[v][0].size()){
            int viz = graph[v][0][i];
            int cviz = comp[viz];
            int cv = comp[v];
            if(cv != cviz){
                cgraph[cv].pb(cviz);
            }
        }
}
ll dp (int v){
    if (dp_[v]) return dp_[v];
    ll ans = 0;
    fin(i,0,cgraph[v].size()){
        int viz = cgraph[v][i];
        ans = max(ans, dp(viz));
    }
    return dp_[v] = ans + coinComp[v];
}
void solve () {
    cin >> n >> m;
    int a,b;
    fin(i,1,n+1){
        cin >> a;
        coin[i] = a;
    }
    fin(i,0,m){
        cin >> a >> b;
        if(a!=b){
            graph[a][0].pb(b);
            graph[b][1].pb(a);
        }
    }
    Kosaraju();
    ll ans = 0;
    fin(i,1,c+1)
        ans = max(ans, dp(i));
    cout << ans << endl;
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}
/*


10 12
1 2 4
5 7 1
4 6 4
7 9 3
9 10 1
7 8 5
1 3 1
6 7 4
4 5 1
3 4 2
8 10 5
2 4 3

*/