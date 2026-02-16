#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define fin(i,a,b) for (int i = a; i <= b; i++)
#define int ll
#define pb push_back
#define f first
#define s second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
const int NMAX = 1e5 + 100;
vi graph[NMAX];
int marc[NMAX], dist[NMAX], pilha[NMAX];
void solve () {
    int n, m;
    cin >> n >> m;
    int a, b;
    fin(i,1,m){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    queue<int> q;
    a = 1, b = n;
    q.push(a); marc[a] = -1;
    while (!q.empty()){
        int v = q.front(); q.pop();
        fin(i,0,((int)graph[v].size())-1){
            int viz = graph[v][i];
            if (!marc[viz]){
                q.push(viz);
                marc[viz] = v;
                dist[viz] = dist[v] + 1;
            }
        }
    }

    if (marc[b]){
        cout << dist[b]+1 << endl;
        int p = -1;
        while (b != a) {
            pilha[++p] = b;
            b = marc[b];
        }
        cout << a;
        while(p>=0)
            cout << ' ' << pilha[p--];
        cout << endl;
    }
    else
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
