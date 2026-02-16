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
vi graph [NMAX], tree [NMAX], vcomp[NMAX];
vii arestas;
int marc[NMAX], pre[NMAX], low[NMAX], comp[NMAX], pilha[NMAX];
int t, p, c;
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
            comp[vertice] = c;
            vcomp[c].pb(vertice);
        } while (vertice != v);
    }
}

void build_BT () {
    p = -1;
    dfs1(1);
    for (auto pp : arestas) {
        int a = pp.f;
        int b = pp.s;

        if (comp[a] != comp[b]) {
            tree[comp[a]].pb(comp[b]);
            tree[comp[b]].pb(comp[a]);
        }
    }
    // cout << "Builded" << endl;
}

ii dfs (int v, int ind) {
    marc[v] = ind;
    ii ans = {v, -1}, aux;
    for (int i = 0; i < tree[v].size(); i++) {
        int viz = tree[v][i];
        if (marc[viz] != ind) {
            aux = dfs(viz, ind);
            if (aux.s > ans.s)
                ans = aux;
        }
    }
    ans.s++;
    return ans;
}

void solve () {
    int n, m;
    // cin >> n >> m;

    FILE* in;
    FILE* out;
    in  = fopen("r", "INPUT.TXT" );
    out = fopen("w", "OUTPUT.TXT");

    fscanf(in, "%d %d ", &n, &m);

    int a, b;
    while (m--) {
        // cin >> a >> b;
        fscanf(in, "%d %d ", &a, &b);
        graph[a].pb(b);
        graph[b].pb(a);
        arestas.pb({a,b});
    }

    build_BT();
    
    ii aux = dfs (1, 2);
    a = aux.f;

    aux = dfs (a, 3);
    b = aux.f;
    
    a = vcomp[a][0];
    b = vcomp[b][0];

    // cout << vcomp[a][0] << ' ' << vcomp[b][0] << endl;
    fprintf(out, "%d %d\n", a, b);
    
    fclose(in);
    fclose(out);
}

int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}