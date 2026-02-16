#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
typedef long double ld;
typedef long long ll;
#define ii pair<int,int>
#define vi vector<int>
#define pb push_back
#define f first
#define s second
using namespace std;
const int INF  = numeric_limits <int> :: max();
const int NMAX = 5e3 + 100;
vi graph [NMAX];
int dist[NMAX], visited[NMAX];
queue <int> tp;
int n, m, d;

int bfs (int fnt) {
    for (int i = 1; i <= n; i++)
        dist[i] = visited[i] = 0;
    tp.push(fnt);
    while (!tp.empty()) {
        int v = tp.front(); tp.pop();
        if (visited[v]) continue;
        visited[v] = true;
        for (int i = 0; i < graph[v].size(); i++) {
            int viz = graph[v][i];
            if (!visited[viz] && dist[viz] == 0) {
                dist[viz] = dist[v] + 1;
                tp.push(viz);
            }
        }
    }
    int r = -1;
    for (int i = 1; i <= n ;i++)
        r = max (r, dist[i]);
    return r;
}

void solve () {
    cin >> n >> m >> d;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    a = -1;
    for (int i = 1; i <= n; i++) {
        // cout << i << ": " << bfs(i) << endl;
        a = max(a, bfs(i));
    }

    a = max (0, 2*d + 1 - a);
    cout << a << ' ' << a << endl;
}


int main() {
    fastio;
    solve();
    return 0;
}