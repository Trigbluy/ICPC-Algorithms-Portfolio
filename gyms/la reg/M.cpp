#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector<int>
#define pb push_back
typedef long long ll;
#define ss second
#define ff first
using namespace std;

const int NMAX = 2e5;
const ll  inf  = numeric_limits<ll> :: max();

int n, m;
vi graph [NMAX], edges[NMAX];

int p, g;

ll dmin[NMAX][2];
int visited[NMAX][2];

priority_queue <pair<int,int>> pq;

void solve () {
    cin >> n >> m >> p >> g;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        graph[a].pb(b);
        graph[b].pb(a);

        edges[a].pb(c);
        edges[b].pb(c);
    }

    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i <= n; i++)
            dmin[i][j] = inf;
        
        // Dijkstra

        pq.push({0, p});

        while (!pq.empty()) {
            auto par = pq.top(); pq.pop();
            int v    = par.ss;
            ll  datt = -par.ff;

            if (visited[v][j]) continue;
            visited[v][j] = 1;

            for (int i = 0; i < graph[v].size(); i++) {
                int viz = graph[v][i];
                int sz  = edges[v][i];

                if (visited[viz][j] == 0) {
                    if (dmin[viz][j] > datt + sz) {
                        dmin[viz][j] = datt + sz;
                        pq.push({-dmin[viz][j], viz});
                    }
                }
            }
        }

        graph[g].clear();
    }

    ll dg = dmin[g][0];

    vi resp;

    for (int i = 1; i <= n; i++) {
        if (dmin[i][0] == 2*dg && dmin[i][1] > dmin[i][0])
            resp.pb(i);
    }

    if (resp.size() == 0) {
        cout << "*" << endl;
        return;
    }
    
    cout << resp[0];
    for (int i = 1; i < resp.size(); i++)
        cout << ' ' << resp[i];
    cout << endl;
}


int main (){
    fastio;
    solve();
    return 0;
}