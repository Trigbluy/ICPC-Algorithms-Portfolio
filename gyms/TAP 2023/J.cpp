#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define f first
#define s second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
const int NMAX = 2e5;
vi graph[NMAX];
int dist[NMAX], marc[NMAX], ndd[NMAX];
int n, m, k, nc, r;
vi d,p,fl;

void bfs (bool frst) {
    // cout << "BFS " << frst << endl;
    queue<ii> tp;
    tp.push({frst?1:n,0});
    while (!tp.empty()){
        ii p = tp.front(); tp.pop();
        int v = p.f, di = p.s;
        // cout << v << ' ' << di << endl;
        if (marc[v] == frst) continue;
        marc[v] = frst;
        if (!frst && dist[v] + di == dist[n])
            ndd[v] = true;
        // cout << v << ' ' << dist[v] << ' ' << di << endl;
        for (int i = 0; i < graph[v].size(); i++) {
            int viz = graph[v][i];
            if (marc[viz] != frst) {
                if (frst) {
                    if(!dist[viz]) 
                        dist[viz] = di+1;
                }
                tp.push({viz,di+1});
            }
        }
    }
}

void ndd_calc () {
    bfs(1), bfs(0);
}

void rem (int v) {
    if (v == 1 || v == n) return;
    if (p[v] && fl[v]) return;
    if (!ndd[v]) return;
    // cout << "Removing " << v << endl;
    ndd[v] = 0;
    for (int i = 0; i < (int)graph[v].size(); i++) {
        int viz = graph[v][i];
        if (ndd[viz]){
            if (dist[viz] == dist[v] + 1)
                fl[viz]--;
            else if (dist[viz] == dist[v] - 1)
                p[viz]--;
            else
                continue;
            rem(viz);
        }
    }
    int nd = --d[dist[v]];
    if (nd == 1)
        nc ++;
    else if (nd == 0){
        r = 1;
        nc = -1;
    }
}
void solve () {
    cin >> n >> m >> k;
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    ndd_calc();
    // for (int i = 1; i <= n; i++)
    //     if (ndd[i])
    //         cout << i << ": " << dist[i] << endl;

    d.assign(n+1,0), p.assign(n+1,0), fl.assign(n+1,0);
    for (int i = 1; i<= n; i++)
        if (ndd[i]){
            d[dist[i]]++;
            for (int j = 0; j < (int)graph[i].size(); j++){
                int viz = graph[i][j];
                if (ndd[viz]) {
                    if (dist[viz] == dist[i] + 1)
                        p[i]++;
                    else if (dist[viz] == dist[i] - 1)
                        fl[i]++;
                }
            }
        }

    for (int i = 1; i < dist[n]; i++)
        if(d[i] == 1) nc++;
    cout << nc;
    for (int i = 0; i < k; i++) {
        cin >> a;

        if (r) {
            cout << " -1";
        }
        else {
            if(ndd[a]){
                p[a] = 0;
                rem (a);
            }
            cout << ' ' << nc;
        }
        // cout << endl;
        // for (int i = 1; i < dist[n]; i++)
        //     cout << "** " << d[i] << endl;  
    }
    cout << endl;
}

int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve ();
    return 0;
}