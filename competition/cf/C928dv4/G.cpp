#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int NMAX = 1e5 + 10;
vector <int> graph[NMAX];
int type [NMAX], playM[NMAX], dontM[NMAX], marc[NMAX];
int ans;
void dfs (int v, int pai) {
    marc[v] = 1;
    int qntfP = 0, qntfD = 0;
    for (int viz: graph[v]) {
        if (viz == pai) continue;
        if (marc[viz] == 0)
            dfs(viz,v);
        if (playM[viz])
            qntfP++;
        if (dontM[viz])
            qntfD++;
    }
    if (type[v] == 0) {
        ans += qntfP;
        return;
    }

    if (type[v] == 1) {
        ans += qntfD;
        return;
    }

    if (type[v] == 2) {
        if (qntfD > qntfP) {
            ans+= qntfP;
            dontM[v] = 1;
        } else if (qntfP > qntfD) {
            ans += qntfD;
            playM[v] = 1;
        }
        else {
            ans += qntfD;
        }
    }
}
void solve () {
    int n;
    cin >> n;
    int a;
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
    }
    memset(type, 0, sizeof (type));
    memset(playM, 0, sizeof (playM));
    memset(dontM, 0, sizeof (dontM));
    memset(marc, 0, sizeof (marc));
    for (int i = 2; i <= n; i++) {
        cin >> a;
        graph[a].pb(i);
        graph[i].pb(a);
    }
    char aux;
    for (int i = 1;i <=n; i++) {
        cin >> aux;
        if (aux == 'C') {
            type[i] = 2;
        } else if (aux == 'P') {
            type[i] = 1;
            playM[i] = 1;
        } else {
            type[i] = 0;
            dontM[i] = 1;
        }
    }
    ans = 0;
    dfs (1,-1);
    cout << ans << endl;
}
int main () {
    int nt;
    cin >> nt;
    while (nt--)
        solve();
    return 0;
}