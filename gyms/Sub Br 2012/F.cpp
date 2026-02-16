#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
typedef long long ll;
typedef long double ld;
using namespace std;
const int NMAX = 2e2;
const int LMAX = 10;
vi graph[NMAX];
int up[NMAX][LMAX];
int marc[NMAX], tin[NMAX], tout[NMAX], h[NMAX];
int t;
void dfs (int v, int p) {
    marc[v] = 1;
    tin[v] = t++;
    up[v][0] = p;
    for (int i = 1; i < LMAX; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (int i = 0; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        if (!marc[viz]) {
            h[viz] = h[v] + 1;  
            dfs (viz, v);
        }
    }
    tout[v] = t++;
}
bool isa (int a, int b) {
    if (tin[a] < tin[b] && tout[b] < tout[a]) return true;
    return false;
}
int lca (int a, int b) {
    if (a==b) return a;
    if (isa(a,b)) return a;
    if (isa(b,a)) return b;
    
    for (int i = LMAX-1; i >= 0; i--)
        if (!isa(up[a][i],b))
            a = up[a][i];
    return up[a][0];
}
int main () {
    fastio;
    int n, a, b, c;
    while (cin >> n) {
        cin >> a >> b >> c;
        for (int i = 0; i <= n + 2; i++) {
            graph[i].clear();
            marc[i] = 0;
        }
        int x, y;
        for (int i = 0; i < n - 1; i ++) {
            cin >> x >> y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        dfs(a, a);
        int l = lca(b,c);
        ld ans = ((ld)(h[c] - h[l]))/((ld) (h[c] + h[b] - 2*h[l]));
        // cout << ans << endl;
        // printf("%.6lf\n", ans);
        cout << setprecision(6) << fixed << ans << endl;
    }
    return 0;
}