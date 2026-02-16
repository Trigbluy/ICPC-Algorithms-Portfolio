#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fin(i,a,b) for(int i = a; i <=(int) b; i++)
#define pb push_back
#define f first
#define s second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
const ll NMAX = 1e5 + 100;
const ll LMAX = 18;
vi graph[NMAX], arestas[NMAX], bct[NMAX];
int marc[NMAX], marcArest[NMAX], pilha[NMAX], compArest[NMAX], artP[NMAX],
    pre[NMAX], low[NMAX], szcomp[NMAX], dp[NMAX], comp[NMAX];
int n, m, k, t, p, c, artp;
ii  arestasN [NMAX];
void nova_bicomp (int idArest) {
    c++;
    int a;
    do {
        a = pilha[p--];
        compArest[a] = c;
        szcomp[c]++;
        comp[arestasN[a].f] = comp[arestasN[a].s] = c;
        // cout << "Creating " << c << ": " << a << endl;
        if(p<=-1)   break;
    } while (a!=idArest);
}

void dfs_tarjan (int v = 1) {
    // cout << "dfs " << v << endl;
    marc[v] = 1;
    low[v] = pre[v] = ++t;
    int qf = 0;
    fin(i,0,((int)graph[v].size()) - 1) {
        int viz = graph[v][i];
        int arestId = arestas[v][i];
        // cout << arestId << endl;
        comp[v] = compArest[arestId];
        if (marcArest[arestId] == 1) continue;
        marcArest[arestId] = 1;
        pilha[++p] = arestId;
        if (!marc[viz]){
            qf++;
            dfs_tarjan(viz);
            low[v] = min (low[v], low[viz]);

            bool nc = false;
            if (v == 1 && qf >= 2) nc = true;
            if (v != 1 && low[viz]>=pre[v]) nc = true;

            if (nc){
                // cout << v << " is artP " << artp +1<< endl;
                artP[v] = ++artp;
                nova_bicomp(arestId);
            }
        }
        else
            low[v] = min(low[v], pre[viz]);
    }
}

void tarjan () {
    t = 0, p = -1, c = 0;
    dfs_tarjan();
    nova_bicomp(-1);
}

void dfs_dp (int v = 1) {
    marc[v] = 1;
    dp[v] += (v <= c && szcomp[c] > 1);
    // cout << "dfs_dp " << v << endl;
    // cout << bct[v].size() << endl;
    fin(i,0,((int)bct[v].size())-1){
        // cout << i << endl;
        int viz = bct[v][i];
        // cout << viz << endl;
        if (!marc[viz]) {
            dp[viz] = dp[v];
            dfs_dp(viz);
        }
    }
}

void build_bct () {
    tarjan();
    // cout << "Tarjan OK " << c << endl;
    fin(v,1,n){
        if (!artP[v]) continue;
        set<int> comps;
        fin(i,0,((int)graph[v].size())-1){
            int idArest = arestas[v][i];
            comps.insert(compArest[idArest]);
        }
        for(int co : comps){
            // cout << "Creating edge " << co << " " << c+artP[v] << endl;
            bct[c+artP[v]].pb(co);
            bct[co].pb(c+artP[v]);
        }
        comp[v] = c + artP[v];
    }
    // cout << "bct ok" << endl;
    fin(i,0,artp+c)
        marc[i] = 0;
    dfs_dp();
    // fin(i,0,artp+c)
    //     cout << "dp[" << i << "] = " << dp[i] << endl;
    // cout << "dp OK" << endl;
}

int tin[NMAX], tout[NMAX];
int up[NMAX][LMAX];

void dfs_lca (int v = 1, int pai = 1) {
    marc[v] = 0;
    tin[v] = ++t;
    up[v][0] = pai;
    fin (i,1,LMAX-1)
        up[v][i]=up[up[v][i-1]][i-1];
    // cout << "LCA " << v << ": ";
    // fin (i,0,LMAX-1)
    //     cout << up[v][i] << ' ';
    // cout << endl;
    fin (i,0,((int)bct[v].size())-1){
        int viz = bct[v][i];
        if (marc[viz])
            dfs_lca(viz,v);
    }
    tout[v] = ++t;
}

bool is_ancestor (int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca (int a, int b) {
    if (is_ancestor(a,b))   return a;
    if (is_ancestor(b,a))   return b;
    for (int i = LMAX - 1; i >= 0; i--)
        if (!is_ancestor(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

void build_lca () {
    dfs_lca();
    // cout << "LCA OK" << endl;
}

void solve () {
    cin >> n >> m >> k;
    int a, b;
    fin(i,1,m){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
        arestas[a].pb(i);
        arestas[b].pb(i);
        arestasN[i]={a,b};
    }
    // cout << "Graph OK" << endl;
    build_bct();
    build_lca();
    while(k--){
        cin >> a >> b;
        int ca = comp[a],
            cb = comp[b],
            l = lca(ca, cb);
        // cout << ca << ' ' << cb  << ' ' << l << endl;
        int val = 2*dp[l] - dp[ca] - dp[cb];
        // cout << val << endl;
        if (val || (ca == cb && a != b))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}

int main () {
    fastio;
    int nt = 1;
    //cin >> nt;
    while (nt--)
        solve();
    return 0;
}