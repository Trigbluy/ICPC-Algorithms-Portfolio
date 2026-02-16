#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define f first
#define s second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
using namespace std;
const int NMAX = 2e5;
const int INF  = numeric_limits<int> :: max();
vi graph [NMAX], cgraph[NMAX], tree [NMAX], vcomp1[NMAX], vcomp2[NMAX], aresta [NMAX];
vector<ii, ii> list_arestas;
vi pts;
int marc[NMAX], marcAr[NMAX], pre[NMAX], low[NMAX], comp1[NMAX], comp2[NMAX], pilha[NMAX], szAr[NMAX];
int t, p, c;
int so, to, ignr;
void dfs1 (int v, int pai = -1) {
    marc[v] = 1;
    low[v] = pre[v] = ++t;
    pilha[++p] = v;
    for (int i = 0 ; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        if (marc[viz] == 0) {
            dfs1 (viz, v);
            low[v] = min (low[v], low[viz]);
        }
        else {
            if (viz == pai) {
                pai=-1;
                continue;
            }
            
            low[v] = min (low[v], pre[viz]);
        }
    }
    if (low[v] == pre[v]) {
        c++;
        int vertice;
        do{
            vertice = pilha[p--];
            comp1[vertice] = c;
            vcomp1[c].pb(vertice);
        } while (vertice != v);
    }
}

void build_CG (int n) {
    t = c = 0, p = -1;

    dfs1(so);
    if (!marc[to] || comp1[so] != comp1[to]) return;

    for (auto pp : list_arestas) {
        int a = pp.f;
        int b = pp.s;

        if (comp1[a] == comp1[so] && comp1[a] == comp1[b]) {
            cgraph[a].pb(b);
            cgraph[b].pb(a);
        }
    }

    for (int i = 1; i <= n; i++)
        if (comp1[i] == comp1[so])
            pts.pb({i});
}

void dfs2 (int v, int pai = -1) {
    marc[v] = 1;
    low[v] = pre[v] = ++t;
    pilha[++p] = v;
    for (int i = 0; i < cgraph[v].size(); i++) {
        int viz = cgraph[v][i];
        int idAr = aresta[v][i];
        
        if (idAr == ignr) continue;
        
        if (marc[viz] == 0) {
            dfs2(viz, v);
            low[v] = min(low[v], low[viz]);
        }
        else {
            if (viz == pai) {
                pai = -1;
                continue;
            }

            low[v] = min(low[v], pre[viz]);
        }
    }

    if (low[v] == pre[v]) {
        c++;
        int vertice;
        do{
            vertice = pilha[p--];
            comp2[vertice] = c;
            vcomp2[c].pb(vertice);
        } while (vertice != v);
    }
}

void build_BT () {
    for (int i : pts) {
        marc[i] = 0;
        comp2[i] = 0;
    }
    c = t = 0, p = -1;
}
void solve () {
    int n, m;
    cin >> n >> m >> so >> to;
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;

        graph[a].pb(b);
        graph[b].pb(a);

        aresta[a].pb(m);
        aresta[b].pb(m);

        list_arestas.pb({{c, m},{a,b}});
        szAr[m] = c;
    }

    build_CG(n);
    if (!marc[to]) {
        cout << -1 << endl;
        return;
    }

    if (comp1[so] != comp1[to]) {
        cout << 1 << endl;
        //
        return;
    }
}

int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}