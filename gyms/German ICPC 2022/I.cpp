#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define vi vector<ll>
#define pb push_back
#define ii pair<int,int>
#define f first
#define s second
#define iii pair<ii,int>
using namespace std;
const int NMAX = 1e5+200;
vi graph[NMAX];
int marc[NMAX], used[NMAX];
iii canNeck[NMAX];
set<int> canLeg[NMAX];
int ans;
void build_man (int nck) {
    used[nck] = 1;
    int trnck = canNeck[nck].s;
    used[trnck] = 1;
    used[canNeck[nck].f.f] = 1,
    used[canNeck[nck].f.s] = 1;
    int a = *canLeg[trnck].begin(),
        b = *canLeg[trnck].rbegin();
    used[a] = used[b] = 1;
    canLeg[trnck].erase(a);
    canLeg[trnck].erase(b);
}
void dfs (int v) {
    marc[v] = 1;
    int cHead = 0;
    for (int i = 0 ; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        if (marc[viz] == 0) {
            dfs (viz);
            if (!used[viz]){
                if (canNeck[viz].f.f && canNeck[viz].f.s && canNeck[viz].s)
                    cHead = viz;
                canLeg[v].insert(viz);
                if (canLeg[viz].size() >= 2)
                    if (!canNeck[v].s)
                        canNeck[v].s = viz;
                    else if (!canNeck[v].f.f)
                        canNeck[v].f.f = viz;
                    else if (!canNeck[v].f.s)
                        canNeck[v].f.s = viz;
                else {
                    if (!canNeck[v].f.f)
                        canNeck[v].f.f = viz;
                    else if (!canNeck[v].f.s)
                        canNeck[v].f.s = viz;
                }
            }
        }
    }
    if (cHead) {
        build_man(cHead);
        ans++;
    }
}
void solve () {
    int n, a;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        graph[a].pb(i);
        graph[i].pb(a);
    }
    dfs(1);
    cout << ans << endl;
}
void precalc () {
}
int main () {
    fastio;
    precalc();
    int nt = 1;
    // cin >> nt;
    while (nt--)
        solve();
    return 0;
}