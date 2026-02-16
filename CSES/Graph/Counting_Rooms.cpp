#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define int ll
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
const int NMAX = 1e3 + 10;
int ma [NMAX][NMAX],marc [NMAX][NMAX];
ii dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};
int n, m;
bool poss (int x, int y){
    return (1<=x&&x<=n) && (1<=y&&y<=m) && (!ma[x][y]);
}
void dfs (int x , int y){
    marc[x][y] = 1;
    for (int d = 0 ; d< 4; d++)
        if (poss(x+dir[d].f, y+dir[d].s) && !marc[x+dir[d].f][y+dir[d].s])
            dfs (x+dir[d].f, y+dir[d].s);
}

void solve () {
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++)
        for (int j = 1 ; j <= m; j++) {
            cin >> c;
            ma[i][j] = c == '#';
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1 ; j <= m; j++)
            if (poss(i,j) && !marc[i][j]){
                dfs(i,j);
                ans++;
            }
    cout << ans << endl;
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}
