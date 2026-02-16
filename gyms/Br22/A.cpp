#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define pb push_back
#define vi vector <int>
using namespace std;
const int NMAX = 2000;
vi graph [NMAX][2];
int marc[NMAX], sz[NMAX], comp[NMAX], pilha[NMAX];
int c, p;
void dfs (int v, int ind) {
    marc[v] = !ind;
    if (ind) {
        comp [v] = c;
        sz[c]++;
    }
    for (int i = 0; i < graph[v][ind].size(); i++) {
        int viz = graph[v][ind][i];
        if (marc[viz] == ind) {
            dfs (viz, ind);
        }
    }
    if(!ind)
        pilha[++p] = v;
}

void solve () {
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        graph[i][0].pb(a);
        graph[i][0].pb(b);
        graph[a][1].pb(i);
        graph[b][1].pb(i);
    }
    p = -1;
    for (int i = 1; i <= n; i++)
        if (marc[i] == 0) {
            dfs (i, 0);
        }
    for (int i = n; i > 0; i--) {
        if (marc[pilha[i]]) {
            c++;
            dfs(pilha[i], 1);
        }
    }
    for (int i = 1; i <= n; i++)
        if (sz[comp[i]] > 1)
            cout << "Y";
        else
            cout << "N";
    cout << endl;
}

int main () {
    fastio;
    solve();
    return 0;
}