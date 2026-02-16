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
const ll M = 1e9+7;
vi graph[NMAX];
ll dp_[NMAX];
int n,m;
ll dp (int v) {
    if(v==n) return 1;
    if(dp_[v] != -1) return dp_[v];
    int ans = 0;
    fin(i,0,graph[v].size()){
        int viz = graph[v][i];
        int d = dp(viz);
        ans = (ans + d) % M;
    }
    // cout << v << ": " << ans << endl;
    return dp_[v] = ans;
}
void solve () {
    cin >> n >> m;
    int a,b;
    fin(i,0,m){
        cin >> a >> b;
        graph[a].pb(b);
    }
    fin(i,1,n+1)
        dp_[i] = -1;
    a = dp(1);
    cout << a << endl;
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