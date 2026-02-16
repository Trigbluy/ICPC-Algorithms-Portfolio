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
const int NMAX = 1e3 + 100;
char grid[NMAX][NMAX];
pair<ii,int> marc[NMAX][NMAX][2];
int dirx[4] = {1,0,-1,0},
    diry[4] = {0,-1,0,1};
char letter[4] = {'R', 'U', 'L', 'D'};
int n, m;
bool poss (int x, int y){
    return (1 <= x && x <= m) && (1<= y && y <= n) && (grid[x][y]!='#');
}
bool on_bound (int x, int y) {
    return (1 == x || x == m) || (1== y || y == n);
}
void win (int x, int y) {
    stack<int> p;
    while(marc[x][y][1].s!=-1){
        p.push(marc[x][y][1].s);
        int nx = marc[x][y][1].f.f, ny = marc[x][y][1].f.s;
        x = nx, y = ny;
    }
    cout << "YES\n";
    cout << p.size() << endl;
    while(!p.empty()){
        cout << letter[p.top()]; p.pop();
    }
    cout << endl;
}
void solve () {
    cin >> n  >> m;
    queue<pair<ii,int>> tp;
    vii monsters;
    int xa, ya;
    fin(j,1,n+1)
        fin(i,1,m+1){
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
                xa = i, ya = j;
            if(grid[i][j] == 'M')
                tp.push({{i,j},0}), marc[i][j][0] = marc[i][j][1] = {{-1,-1},-1};
        }
    tp.push({{xa,ya},1}), marc[xa][ya][1] = {{-1,-1},-1};
        
    
    while (!tp.empty()){
        auto p = tp.front(); tp.pop();
        int x = p.f.f, y = p.f.s, t = p.s;
        // cout << x << ' ' << y << ' ' << t << endl;
        if (t && on_bound(x,y)){
            win(x,y); return;
        }
        fin(d,0,4){
            int xv = x + dirx[d], yv = y + diry[d];
            // cout << " to " << xv << " " << yv << ' ';
            if (poss(xv,yv) && !marc[xv][yv][t].f.f){
                // cout << " going." << endl;
                marc[xv][yv][t] = {{x,y}, d};
                if(!t && !marc[xv][yv][1].f.f)
                    marc[xv][yv][1].f = {x,y};
                tp.push({{xv,yv}, t});
            }
        }
    }
    cout << "NO\n";
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}
