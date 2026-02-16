#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define fin(i,a,b) for(int i = a; i <= (int)b; i++)
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
char ma[NMAX][NMAX];
pair<ii,int> marc[NMAX][NMAX];
int pilha[NMAX*NMAX];
int n, m;
bool poss (int x, int y) {
    return (1<=x && x <= n) && (1<=y && y <= m) && (ma[x][y] != '#');
}
int dirx[4] = {1,0,-1,0},
    diry[4] = {0,1,0,-1};
char letter[4] = {'D','R','U','L'};

void solve () {
    cin >> n >> m;
    int xa, ya, xb, yb;
    fin(i,1,n)
        fin(j,1,m){
            cin >> ma[i][j];
            if(ma[i][j] == 'A')
                xa = i, ya = j;
            if(ma[i][j] == 'B')
                xb = i, yb = j;
        }
    queue<ii> q;
    marc[xa][ya] = {{-1, -1},-1};
    q.push({xa,ya});
    while(!q.empty()){
        ii p = q.front(); q.pop();
        int x = p.f, y = p.s;
        // cout << x << ',' << y << " from " << marc[x][y].s << " " << marc[x][y].f.f << "," <<  marc[x][y].f.s << endl;
        fin(d,0,3){
            int xv = x + dirx[d], yv = y + diry[d];
            if (poss(xv,yv) && !marc[xv][yv].f.f){
                marc[xv][yv] = {{x,y},d}, q.push({xv,yv});
            }
        }
    }
    int p = -1;
    if (marc[xb][yb].f.f) {
        cout << "YES" << endl;
        while (xb != -1){
            // cout << xb << ' ' << yb << endl;
            pilha[++p] = marc[xb][yb].s;
            int nx = marc[xb][yb].f.f;
            int ny = marc[xb][yb].f.s;
            yb = ny;
            xb = nx;
        }
        cout << p << endl;
        while (p>0){
            cout << letter[pilha[--p]];
        }
        cout << endl;
    }
    else    
        cout << "NO" << endl;
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}
