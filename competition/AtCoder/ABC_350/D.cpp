#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pb push_back
#define vi vector<int>
typedef long long ll;
using namespace std;
const int NMAX = 2e5+100;
vi graph[NMAX];
int marc[NMAX];
ll nv;
void dfs (int v) {
    marc[v] = 1;
    nv ++;
    for (int i = 0; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        if(marc[viz] == 0) {
            dfs (viz);
        }
    }
}
int main () {
    fastio;
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    ll ans = - m;
    for (int i = 1; i <= n; i++)
        if (marc[i] == 0) {
            nv = 0;
            dfs(i);
            ans += nv*(nv-1)/2;
        }
    cout << ans << endl;
    return 0;
}