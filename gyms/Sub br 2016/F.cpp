#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int> 

using namespace std;
const int NMAX = 2e4;
ii tree[NMAX];
int csz [NMAX];

int dfs (int v) {
    if (tree[v].ff) {
        csz[tree[v].ff] = 1;
        csz[v] += dfs (tree[v].ff);
    }
    if (tree[v].ss) {
        csz[tree[v].ss] = 1;
        dfs (tree[v].ss);
    }
    return csz[v];
}

void solve () {
    int n, a, b, c, maxa, ta, maxb, tb, ntotal;
    cin >> n;
    ntotal = n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        tree[a] = {c, b};
    }

    csz[1] = 1;
    ta = dfs (1);
    maxa = 0;
    for (int i = 1; i <= n; i++)
        if (maxa < csz[i]) {
            maxa = csz[i];
        }
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        tree[a] = {b, c};
        csz[a] = 0;
    }

    csz[1] = 1;
    tb = dfs (1);
    maxb = 0;
    for (int i = 1; i <= n; i++)
        if (maxb < csz[i])
            maxb = csz[i];
    
    ntotal += n;
    cout << ntotal - max (min(ta, maxb), min(tb, maxa)) << endl;
}

int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}