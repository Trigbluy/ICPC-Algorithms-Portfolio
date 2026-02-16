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
const int NMAX = 5e3+100;
vi graph[NMAX];
int marc[NMAX];
void dfs (int v) {
    // cout << " %" << v << endl;
    marc[v] = 1;
    fin(i,0,graph[v].size()){
        int viz = graph[v][i];
        if (!marc[viz])
            dfs(viz);
    }
} 
void solve () {
    int n, m;
    cin >> n >> m;
    vector<pair<ii,ll>> edges;
    int a, b, c;
    fin(i,0,m){
        cin >> a >> b >> c;
        edges.pb({{a,b},c});
        graph[a].pb(b);
    }
    vll d(n+1,NINF), ant(n+1,-1);
    d[1] = 0;
    bool any = false;
    fin(i,0,n){
        any = false;
        for(auto t : edges){
            a = t.f.f, b = t.f.s, c = t.s;
            if(d[a] != NINF){
                if (d[b] < d[a] + c){
                    d[b] = d[a] + c;
                    any = true;
                }
            }
        }
        // cout << i << ": ";
        // fin(j,1,n+1)
        //     cout << d[j] << ' ';
        // cout << endl;
        if (!any)
            break;
    }

    if (!any){
        cout << d[n] << endl;
        return;
    }
    // cout << "Tem ciclo positivo" << endl;
    vll att;
    for(auto t : edges){
        a = t.f.f, b = t.f.s, c = t.s;
        if(d[a] != NINF){
            if (d[b] < d[a] + c){
                d[b] = max(d[b], d[a] + c);
                att.pb(b);
            }
        }
    }

    for (int v : att) {
        if (!marc[v]){
            dfs(v);
        }
    }
    if (marc[n])
        cout << -1 << endl;
    else
        cout << d[n] << endl;
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

5 5
1 2 2
2 3 10
3 4 100
4 2 1000
1 5 10



4 4
1 4 1
2 4 1
2 3 1
3 2 1

*/