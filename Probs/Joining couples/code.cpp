#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define endl '\n'

using namespace std;

const int NMAX = 1e5 + 100;
const int LMAX = 21;

// Kosaraju

vi graph[NMAX][2], cgraph[NMAX];
int marc[NMAX], pilha [NMAX], comp[NMAX], sz_comp[NMAX], in_pos[NMAX];
ii arestas[NMAX];

int n, m, c, p;

// LCA

int prof[NMAX], tin [NMAX], tout[NMAX], connection[NMAX];
int up[NMAX][LMAX];

int t;

// Kosaraju

void dfsK (int v, int ind) {
    marc[v] = !ind;
    for (int i = 0; i < graph[v][ind].size(); i++) {
        int viz = graph[v][ind][i];
        if (marc[viz] == ind) {
            dfsK(viz, ind);
        }
    }
    if (ind) {
        comp[v] = c;
        in_pos[v] = ++sz_comp[c];
    }
    else {
        pilha[++p] = v;
    }
}

void kosaraju () {
    p = -1 , c = 0;
    for (int i = 1; i <= n; i++)
        if (marc[i] == 0)
            dfsK(i,0);

    while (p >= 0) {
        int noh = pilha[p--];
        if (marc[noh] == 1) { 
            c++;
            sz_comp[c] = 0;
            dfsK(noh, 1);
        }
    }
    
    for (int i = 1; i <= m; i++) {
        int a = arestas[i].ff;
        int b = arestas[i].ss;
        
        if (comp[a] != comp[b]) {
            cgraph[comp[b]].pb(comp[a]);
            if (sz_comp[comp[b]] > 1)
                connection[comp[a]] = b;
        }
    }
}

// LCA

void dfsLCA (int v, int pai) {
    marc[v] = 1;
    tin[v] = ++t;

    up[v][0] = pai;
    for (int j = 1; j < LMAX; j++)
        up[v][j] = up[up[v][j-1]][j-1];
    
    for (int i = 0; i < cgraph[v].size(); i++) {
        int viz = cgraph[v][i];
        if(marc[viz] == 0 && viz != pai) {
            prof[viz] = prof [v] + 1;
            if (connection[v] != -1) {
                connection[viz] = connection[v];
            }
            dfsLCA (viz, v);
        }
    }

    tout[v] = ++t;
}

bool is_ancestor (int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca (int a, int b) {
    if (is_ancestor(a, b))
        return a;
    if (is_ancestor(b,a))
        return b;

    for (int j = LMAX - 1; j >= 0; j--)
        if (!is_ancestor(up[a][j], b))
            a = up[a][j];
    return up[a][0];
}

void prepare () {
    t = 0;
    for (int i = 1; i <= c; i++)
        if(sz_comp[i] > 1 && marc[i] == 0) {
            prof[i] = 1;
            connection[i] = -1;
            dfsLCA(i,i);
        }
}

int dist (int a, int b) {
    int u = comp[a];
    int v = comp[b];

    if (up[u][LMAX-1] != up[v][LMAX-1])
        return -1;

    int l = lca(u,v);
    int ans = prof[u] + prof[v] - 2 * prof[l];
    
    if (sz_comp[l] > 1) {
        
        int i = connection[u];
        int j = connection[v];
        
        if (i == -1) i = a;
        if (j == -1) j = b;
        
        i = in_pos[i];
        j = in_pos[j];
        
        if (i > j) swap(i,j);
        
        ans += min (j - i, sz_comp[l] - (j - i));
    }

    return ans;
}

void restart () {
    for (int i = 0 ; i < n + 10; i++){
        graph[i][0].clear();
        graph[i][1].clear();
        cgraph[i].clear();
        marc[i] = tin[i] = tout[i] = 0;
    }
}

int main () {
    fastio;
    while (cin >> n) { 
        m = n;
        restart();

        int aux;
        for (int i = 1; i <= n; i++) {
            cin >> aux;

            graph[i]  [0].pb(aux);
            graph[aux][1].pb(i);

            arestas[i] = {i, aux};
        }

        kosaraju();
        prepare();

        int q, a, b;
        cin >> q;
        while (q--) {
            cin >> a >> b;
            cout << dist(a, b) << endl;
        }
    }
    return 0;
}