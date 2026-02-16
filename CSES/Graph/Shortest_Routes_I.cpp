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
const int INF = numeric_limits<int> :: max();
const int NMAX = 1e5 + 100;
vi graph[NMAX], szArest[NMAX];
int dist[NMAX], marc[NMAX];
void solve () {
    int n, m;
    cin >> n >> m;
    int a, b, c;
    fin(i,1,m+1){
        cin >> a >> b >> c;
        graph[a].pb(b);
        szArest[a].pb(c);
    }
    fin(i,2,n+1)
        dist[i] = INF;
    priority_queue<ii> tp;
    tp.push({0,1});
    while(!tp.empty()){
        ii p = tp.top(); tp.pop();
        int dst = -p.f, v = p.s;
        if (marc[v]) continue;
        marc[v] = 1;
        fin(i,0,graph[v].size()){
            int viz = graph[v][i];
            int sz  = szArest[v][i];
            if (!marc[viz] && dist[viz] > dst + sz){
                dist[viz] = dst + sz;
                tp.push({-dist[viz], viz});
            }
        }
    }
    cout << 0;
    fin (i,2,n+1)
        cout << ' ' << dist[i];
    cout << endl;
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}