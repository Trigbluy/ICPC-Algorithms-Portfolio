#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
#define ull unsigned ll
#define ld long double
#define pb push_back
#define int ll
#define vi vector<int>
using namespace std;

const int NMAX = 3e5 + 10;
const int M    = 998244353;

vi graph [NMAX];
int dfs_[NMAX], marc[NMAX];
int n;

ll dfs (int v, int pai) {

    if (dfs_[v] != -1) return dfs_[v];
    marc[v] = 1;

    ull ans = 1;
    for (auto viz : graph[v]) {
        if (viz == pai) continue;
        ans = (ans * ( (dfs(viz,v) + 1) % M )) % M;
        // cout << "Calc " << v << " with " << viz << " : " << dfs(viz, -1) << endl;
    }

    dfs_[v] = ans % M;
    return ans % M;
}

void solve () {
    cin >> n;

    for (int i = 0; i <= n + 2; i++) {
        graph[i].clear();
        dfs_[i] = -1;
    }

    int a,b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    ull ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dfs(i, -1)) % M;
        // cout << dfs(i,-1) << ' ';
    }

    cout << (ans + 1) % M << endl;
}

signed main (){
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}