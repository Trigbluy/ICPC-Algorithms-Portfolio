#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
#define ii pair<ll,ll>
#define vi vector<int>
#define vii vector<ii>
using namespace std;
map<int, ii> graph;

void solve () {
    int n;
    cin >> n;
    ll start, ant, antt, aux;
    cin >> start;
    ant  = start;
    antt = -1;
    for (int i = 1; i < n ; i++){
        cin >> aux;
        graph[ant] = {antt, aux};
        antt = ant;
        ant = aux;
    }
    graph[aux] = {antt, -1};

    int q;
    cin >> q;
    while (q--) {
        ll tp, x, y;
        cin >> tp >> x;

        auto p = graph[x];
        if (tp == 1) {
            cin >> y;
            graph[y] = {x, p.ss};
            graph[x].ss = y;
        }
        else {
            if (p.ff != -1) {
                graph[p.ff].ss = p.ss;
            } else {
                start = p.ss;
            }

            graph[p.ss].ff = p.ff;
        }
    }

    ll p = start;
    cout << p;
    p = graph[p].ss;
    while (p != -1) {
        cout << ' ' << p;
        p = graph[p].ss;
    }
    cout << endl;
}

int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}