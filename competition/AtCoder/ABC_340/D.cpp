#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define int ll
using namespace std;
const signed NMAX = 2e5+10;
vector <int> graph[NMAX], arestas[NMAX];
int min_dist[NMAX], visited[NMAX];
int n;

priority_queue<pair<int,int>> dj;

signed main () {
    cin >> n;
    int a, b, c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;

        graph[i].pb(i+1);
        arestas[i].pb(a);

        graph[i].pb(c);
        arestas[i].pb(b);

        min_dist[i + 1] = numeric_limits <int> :: max();
    }
        min_dist[1] = 0;
    
    dj.push({0,1});
    while (!dj.empty()) {
        int v = dj.top().second; dj.pop();

        if (visited[v]) continue;
        visited[v] = true;

        for (int i = 0; i < graph[v].size(); i++) {
            int viz  = graph[v][i];
            int dist = arestas[v][i];

            if(visited[viz] == true) continue;

            if (min_dist[viz] > min_dist[v] + dist) {
                min_dist[viz] = min_dist[v] + dist;
            }
            dj.push({-min_dist[viz], viz});
        }
    }
    // for (int i = 1; i <= n; i++)
    cout << min_dist[n] << endl;
    return 0;
}