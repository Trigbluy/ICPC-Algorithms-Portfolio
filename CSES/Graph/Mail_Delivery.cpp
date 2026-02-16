#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define int ll
#define pb push_back
#define vi vector<int>
 
const int NMAX = 2e5 + 10;
 
using namespace std;
 
vector<int> graph[NMAX], arestas [NMAX];
int degree[NMAX], marc[NMAX], marcArest[NMAX];
int numero_arestas_marcadas;
 
void dfs1 (int v, int pai) {
    marc[v] = 1;
    
    for (int i = 0; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        int idArest = arestas[v][i];
 
        degree[v]++;
 
        if (marcArest[idArest] == 1) continue;
        marcArest[idArest] = 1;
        numero_arestas_marcadas++;
 
        if (marc[viz] == 0)
            dfs1(viz, v);
    }
}
 
void dfs2 (int v) {
    while (degree[v] > 0) {
        int ind     = degree[v] - 1;
        int viz     = graph[v][ind];
        int idArest = arestas[v][ind];

        degree[v]--;

        dfs2(viz);
    }

    cout << v << ' ';
}
 
void solve () {
    int n, m;
    cin >> n >> m;
 
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
 
        graph[a].pb(b);
        graph[b].pb(a);
 
        arestas[a].pb(i);
        arestas[b].pb(i);
    }
 
    dfs1(1,-1);
 
    int n_i = 0;

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1){
            n_i++;      break;
        }
    }
 
    if (n_i != 0 || numero_arestas_marcadas != m){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
 
    dfs2 (1);
    
    cout << endl;
    return;
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}
