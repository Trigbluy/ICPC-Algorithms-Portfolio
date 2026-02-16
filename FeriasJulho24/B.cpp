#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ffr(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define f first
#define s second
typedef vector<int> vi;
typedef pair<int,int> ii;
using namespace std;
const int INF = numeric_limits<int> :: max();
const int NMAX = 2e3;
vi graph[NMAX], arest[NMAX];

vi dijkstra (int n) {
    vi dist(n+1,INF), marc(n+1,0);
    priority_queue<ii> tp;
    tp.push({0,n});
    dist[n] = 0;
    while(!tp.empty()) {
        ii p = tp.top(); tp.pop();
        int t = p.f;
        int v = p.s;

        if (marc[v])    continue;
        marc[v] = 1;

        ffr(i,0,graph[v].size()) {
            int viz = graph[v][i];
            int art = arest[v][i];

            if (!marc[viz] && t + art < dist[v]) {
                dist[viz] = t + art;
                tp.push({-dist[viz], viz});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, a, b, c;
    cin >> n >> m;
    ffr(i,0,m) {
        cin >> a >> b >> c;
        graph[a].pb(b);
        graph[b].pb(a);

        arest[a].pb(c);
        arest[b].pb(c);
    }

    vi dist = dijkstra(n);
    int ans = 0;
    ffr(i,0,graph[1].size()){
        int viz = graph[1][i];
        int art = arest[1][i];
        if (dist[viz] + )
    }
}
int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}