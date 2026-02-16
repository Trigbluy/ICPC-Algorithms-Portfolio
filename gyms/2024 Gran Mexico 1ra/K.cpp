#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(), cout.tie()
#define frm(i,a,b) for (int i = a; i < b; i++)
#define frl(i,a,b) for (int i = a; i > b; i--)
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define f first
#define s second
using namespace std;
const int NMAX = 1000;
vi graph[NMAX];
int marc[NMAX];
ii dfs (int v) {
    marc[v] = 1;
    ii ans = {1,0};
    for (int i = 0; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        if (marc[viz] == 0) {
            ii aux = dfs(viz);
            ans = {ans.f + min(aux.f,aux.s), ans.s + aux.f};
        }
    }
    return ans;
}
void solve () {
    int n, k, a, b;
    cin >> n >> k;
    vii horses;
    frm (i, 0, k) {
        cin >> a >> b;
        horses.pb({a,b});
    }
    frm(i,0,k)
        frm(j,i+1,k)
            if ((abs(horses[i].f - horses[j].f) == 1 && abs(horses[i].s - horses[j].s) == 2) ||
                (abs(horses[i].f - horses[j].f) == 2 && abs(horses[i].s - horses[j].s) == 1)) {
                    graph[i].pb(j);
                    graph[j].pb(i);
                }
    
    int ans = 0;
    frm(i,0,k){
        if (marc[i] == 0) {
            ii aux = dfs(i);
            ans += min(aux.f, aux.s);
        }
    }
    cout << ans << endl;
}
int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}