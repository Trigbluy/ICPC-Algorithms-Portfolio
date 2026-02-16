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
int h[NMAX], p[NMAX];
bool dfs (int v){
    marc[v]= 1;
    fin(i,0,graph[v].size()){
        int viz = graph[v][i];
        if (!marc[viz]){
            h[viz] = h[v] + 1;
            p[viz] = v;
            if(dfs(viz))
                return true;
        }
        else {
            if (viz == p[v]) continue;
            cout << h[v] - h[viz] + 2 << endl;
            cout << viz;
            int node = v;
            while(node != viz){
                cout << ' ' << node;
                node = p[node];
            }
            cout << ' ' << viz << endl;
            return true;
        }
    }
    return false;
}
void solve () {
    int n, m;
    cin >> n >> m;
    int a, b;
    fin(i,0,m){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
 
    fin(i,1,n+1)
        if (!marc[i] && dfs(i))
            return;
    cout << "IMPOSSIBLE\n";
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}