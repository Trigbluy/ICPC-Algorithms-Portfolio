#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
const int NMAX = 4e5;
vi graph[NMAX];
int marc[NMAX], dist[NMAX][2];

int n, m, k;

struct frac {
    ll p,q;
    frac(ll a, ll b = 1) : p(a/__gcd(a,b)), q(b/__gcd(a,b)) {;}
    frac operator+ (frac a) {
        return frac((p*a.q + q*a.p)/__gcd((p*a.q + q*a.p), q*a.q), q*a.q/__gcd((p*a.q + q*a.p),q*a.q));
    }
    frac operator* (frac a) {
        return frac((p*a.p)/__gcd((p*a.p), q*a.q), (q*a.q)/__gcd((p*a.p), q*a.q));
    }
    bool operator< (frac a) {
        return (p*a.q) < (q*a.p);
    }
    frac print() {
        cout << "Printing: " << p << '/' << q << endl;
        return frac(p,q);
    }
};
void bfs (int ind) {
    queue<int> tp;
    tp.push(ind? 1: n); // dist[0] = até o n, dist[1] = saindo do 1
    while(!tp.empty()) {
        int v = tp.front(); tp.pop();
        if(marc[v] == ind) continue;
        marc[v] = ind;

        for (int i = 0; i < graph[v].size(); i++){
            int viz = graph[v][i];
            if (marc[viz] != ind && dist[viz][ind] == 0){
                dist[viz][ind] = dist[v][ind] + 1;
                tp.push(viz);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    vi woorms;
    int a, b;
    for (int i = 0; i < k; i++){
        cin >> a;
        woorms.pb(a);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bfs(1);
    bfs(0);

    // for (int i = 0; i < 2; i++) {
    //     cout << i << ": ";
    //     for (int j = 1; j <= n; j++) {
    //         cout << j << ": " << dist[j][i] << endl;
    //     } 
    // }
    ll smWo = 0;
    for (int i = 0; i < woorms.size(); i++)
        smWo += dist[woorms[i]][0];
    frac ans(dist[n][1]);
    for (int i = 0; i < woorms.size(); i++) {
        frac aux(dist[woorms[i]][1]);
        // aux.print();
        aux = aux + frac(smWo - dist[woorms[i]][0], k-1);
        // aux.print();
        // cout << endl;
        if (aux < ans)
            ans = aux;
    }
    cout << ans.p << '/' << ans.q << endl;
}

int32_t main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}