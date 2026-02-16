#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false) , cin.tie(0), cout.tie(0)
#define pb push_back
using namespace std;
typedef vector<int> vi;
const int NMAX = 2e5;
vi graph[NMAX];
int marc[NMAX], pros[NMAX];
priority_queue<int> tp;
void dfs (int v, int d) {
    marc[v] = d;
    if (!pros[v]){
        tp.push(-v);
        pros[v] = 1;
    }
    if (!d) return;
    for (int i = 0 ; i < (int)graph[v].size(); i++) {
        int viz = graph[v][i];
        if (marc[viz] < d) {
            dfs(viz, d-1);
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    tp.push(-1);
    queue<int> ans;
    while (!tp.empty()){
        int v = -tp.top(); tp.pop();
        pros[v] = 1;
        ans.push(v);
        dfs(v, k);
    }

    cout << ans.front(); ans.pop();
    while (!ans.empty()) {
        cout << ' ' << ans.front();
        ans.pop();
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