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
vi graph[NMAX][2], arestas[NMAX][2];
vll d[2];
int marc[NMAX];
int n, m;
void dijkstra (int ind) {
    priority_queue<ii> tp;
    int from = ind?n:1;
    tp.push({0,from});
    d[ind][from] = 0;
    while(!tp.empty()) {
        ii p = tp.top(); tp.pop();
        int v = p.s;
        if (marc[v] == !ind) continue;
        marc[v] = !ind;
        // cout << v << endl;
        fin(i,0,graph[v][ind].size()){
            int viz = graph[v][ind][i];
            int sz = arestas[v][ind][i];
            if (d[ind][viz] > d[ind][v] + sz){
                d[ind][viz] = d[ind][v] + sz;
                tp.push({-d[ind][viz], viz});
            }
        }
    }
}
void solve () {
    cin >> n >> m;
    int a, b, c;
    vector<pair<ii,int>> edges;
    fin(i,0,m){
        cin >> a >> b >> c;
        graph[a][0].pb(b);
        graph[b][1].pb(a);
        arestas[a][0].pb(c);
        arestas[b][1].pb(c);
        edges.pb({{a,b},c});
    }
    // cout << "Leu" << endl;
    fin(i,0,2)
        d[i].assign(n+1,INF);
    dijkstra(0);
    dijkstra(1);
    // fin(j ,0,2){
    //     fin(i,1,n+1)
    //         cout << d[j][i] << ' '; cout << endl;}
    ll ans = INF;
    for (auto e : edges){
        a = e.f.f, b = e.f.s, c = e.s;
        if (d[0][a] != INF && d[1][b] != INF)
            ans = min(ans, d[0][a] + d[1][b] + c/2);
    }

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