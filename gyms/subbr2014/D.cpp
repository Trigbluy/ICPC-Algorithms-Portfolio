#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define vi vector<int>
#define pb push_back
#define ii pair<ll,ll>
#define lll pair<ll,ii>
#define f first
#define s second
using namespace std;
const int NMAX = 4e4;
const int INF = numeric_limits<int> :: max();
vi graph [NMAX], aresta[NMAX], arestaid[NMAX];
int comp[NMAX], marc[NMAX], marcArest[NMAX], szComp[NMAX], lenComp[NMAX],
    low[NMAX], pre[NMAX], pilha[NMAX];
int t, c, p;
    int n, m, q;

int dist[NMAX];

void dfs (int v) {
    marc[v] = 1;
    low[v] = pre[v] = ++t;
    pilha[++p] = v;
    for (int i = 0 ; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        int idArest = arestaid[v][i];

        if (marcArest[idArest]) continue;
        marcArest[idArest] = 1;
        
        if (marc[viz] == 0) {
            dfs(viz);
            low[v] = min(low[v], low[viz]);
        }
        else {
            low[v] = min (low[v], pre[viz]);
        }
    }
    if (low[v] == pre[v]) {
        int vertice;
        c++;
        do {
            vertice = pilha[p--];
            comp[vertice] = c;
            szComp[c]++;
        } while(vertice != v);
    }
}

void dijkstra (int so) {
    for (int i = 0 ; i< NMAX; i++)
        dist[i] = INF;
    vi visited(n+1, 0);
    priority_queue<ii> tp;
    dist[so] = 0;
    tp.push({0, so});
    while(!tp.empty()) {
        auto p = tp.top(); tp.pop();

        int v = p.s;
        int t = -p.f;
        if (visited[v]) continue;
        visited[v] = 1;

        for (int i = 0; i < graph[v].size(); i++) {
            int viz = graph[v][i];
            int sz   = aresta[v][i];

            if (!visited[viz] && dist[viz]>dist[v]+sz) {
                dist[viz] = dist[v]+sz;
                tp.push({-(t+sz), viz});
            }
        }
    }
}

int main () {
    fastio;
    cin >> n >> m;
    int a,b,c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;

        graph[a].pb(b);
        graph[b].pb(a);

        aresta[a].pb(c);
        aresta[b].pb(c);

        arestaid[a].pb(i);
        arestaid[b].pb(i);
    }
    for (int i = 1; i <= n; i++)
        if (!marc[i]){
            dfs(i);
            p = -1;
        }
    for (int i = 1; i <= n; i ++){
        for (int j = 0; j < graph[i].size(); j++) {
            int viz = graph[i][j];
            int idArest = arestaid[i][j];
            int sz = aresta[i][j];
            if (marcArest[idArest] == 2) continue;
            marcArest[idArest] = 2;
            if (comp[i] == comp[viz])
                lenComp[comp[i]] += sz;
        }
    }
    cin >> q;
    while (q--) {
        int so, len;
        cin >> so >> len;
        dijkstra(so);
        int ans = INF;
        for (int i = 1; i <=n ;i++) {
            // cout << comp[i] << ' ' << lenComp[comp[i]] << endl;
            if (lenComp[comp[i]] >= len && dist[i] != INF && szComp[comp[i]] > 1) {
                // cout << lenComp[i] + 2*dist[i] << endl;
                ans = min(ans, lenComp[comp[i]] + 2*dist[i]);
            }
        }
        if (ans == INF)
            cout << -1 << endl;
        else
        cout << ans << endl;
    }
    return 0;
}