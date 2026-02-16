#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < b; i++)
#define f first
#define s second
#define endl '\n'
#define int ll
const signed NMAX = 1*1e3 + 1;
const signed M = 998244353;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<int,int> mpii;

int marc[NMAX][NMAX];
string grid[NMAX];
set<ii> portals[NMAX];

void solve(){
    int h, w;
    cin >> h >> w;
    fin(i,0,h)
        cin >> grid[i];


    fin(i,0,h)
        fin(j,0,w)
            if (grid[i][j] != '.' && grid[i][j] != '#')
                portals[grid[i][j]].insert({i,j});

    queue<pair<ii,int>> qq;
    qq.push({{0,0},0});
    while(!qq.empty()){
        auto p = qq.front(); qq.pop();
        int x = p.f.f;
        int y = p.f.s;
        int d = p.s;
        marc[x][y] = 1;
        // cout << x << ' ' << y << ' ' << d << endl;
        if (x == h-1 && y == w-1){
            cout << d << endl;
            return;
        }
        ii mv[4] = {{1,0},{-1,0},{0,1},{0,-1}};
        fin(i,0,4){
            int xt = x + mv[i].f;
            int yt = y + mv[i].s;
            if (0 <= xt && xt < h)
                if (0 <= yt && yt < w)
                    if (grid[xt][yt] != '#')
                        if (!marc[xt][yt]){
                            marc[xt][yt] = 1;
                            qq.push({{xt,yt},d+1});
                        }
        }
        bool enter = false;
        if (grid[x][y] != '.' && grid[x][y] != '#')
            for (ii t : portals[grid[x][y]])
                if (t != p.f && !marc[t.f][t.s]){
                    qq.push({t,d+1});
                    marc[t.f][t.s] = 1;
                    enter = true;
                }
        if (enter)
            portals[grid[x][y]].clear();
    }
    cout << -1 << endl;
}

signed main (){
    fastio;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}