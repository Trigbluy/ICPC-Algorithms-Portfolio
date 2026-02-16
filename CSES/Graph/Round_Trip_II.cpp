#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define fin(i,a,b) for (int i = a; i < (int) b; i++)
#define int ll
#define pb push_back
#define f first
#define s second
// #define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
const ll INF = numeric_limits<ll> :: max();
const ll NINF = -(INF-1);
const int NMAX = 2e5+100;
vi graph[NMAX];
int marc[NMAX], pross[NMAX], p [NMAX], pre[NMAX], low[NMAX], h[NMAX];
int t;
bool dfs (int v) {
    // cout << "DFS in " << v << endl;
    marc[v] = 1;
    low[v] = pre[v] = ++t;
    fin(i,0,graph[v].size()){
        int viz = graph[v][i];
        if (!marc[viz]){
            p[viz] = v;
            h[viz] = h[v] + 1;
            if (dfs(viz))
                return true;
        }
        else {
            if (pross[viz]) continue;

            int cur = v;
            vi nodes;
            while (cur != -1 && p[cur] != viz){
                cur = p[cur];
                nodes.pb(cur);
            }
            nodes.pb(viz);
            reverse(nodes.begin(), nodes.end());
            cout << nodes.size() + 2 << endl << v;
            for(int i : nodes)
                cout << ' ' << i;
            cout << ' ' << v << endl;
            return true;
        }
    }
    pross[v] = 1;
    return false;
}
void solve () {
    int n, m;
    cin >> n >> m;
    int a, b;
    fin(i,0,m){
        cin >> a >> b;
        graph[a].pb(b);
    }
    fin(i,1,n+1)
        if (!marc[i])
            if (dfs(i))
                return;
    cout << "IMPOSSIBLE\n";
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}
/*


10 12
1 2 4
5 7 1
4 6 4
7 9 3
9 10 1
7 8 5
1 3 1
6 7 4
4 5 1
3 4 2
8 10 5
2 4 3

*/