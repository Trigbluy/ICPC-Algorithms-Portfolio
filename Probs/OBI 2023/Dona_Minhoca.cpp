#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector<int>
#define pb push_back
using namespace std;
const int NMAX = 3e5 + 10;
vi  graph [NMAX];
int marc [NMAX], prot [NMAX];
int n, radares, n_prot, k;

void proteg (int v, int qnt) {
    prot[v] = qnt;
    if (qnt <= 0)   return;
    n_prot ++;
    for (int i = 0; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        if (prot[viz] < qnt - 1)
            proteg(viz, qnt-1);
    }
}

int dfs (int v, int r) {
    if (radares > k || n_prot >= n) return -1;
    marc[v] = 1;
    int qf = 0, mx = - 1;
    for (int i = 0 ; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        if (marc[viz] == 0) {
            qf++;
            mx = max(mx, dfs(v, r));
        }
    }
    if (mx == -1 && prot [v] >= 1) {
        return -1;
    }

    if (mx == r - 1) {
        proteg(v, r);
        radares++;
        return -1;
    }

    if (qf == 0)
        return !prot[v] - 1;
    return mx + 1;
}

bool poss (int r) {
    n_prot  = 0;
    radares = 0;

    memset(marc, 0, sizeof(marc));
    memset(prot, 0, sizeof(prot));

    dfs(1, r);

    return radares + (n_prot < n) <= k;
}

void solve () {
    cin >> n >> k;

    int a, b;
    for (int i = 0 ; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int l = 0;
    int r = n/k;
    int m;
    while (l < r) {
        m = (l+r)/2;
        if (poss(m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l << endl;
}

int main () {
    fastio;
    int nt = 1;
    //cin >> nt;
    while (nt--)
        solve();
    return 0;
}