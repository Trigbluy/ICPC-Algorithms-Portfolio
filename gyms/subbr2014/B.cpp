#include <bits/stdc++.h>
typedef long long ll;
#define vi vector<int>
#define pb push_back
using namespace std;
const int NMAX = 3e5 + 100;
int marc[NMAX];
vi graph;

// int dfs (int v) {
//     if (marc[v]) {return 0;}
//     cout << "dfs " << v << endl;
//     marc[v] = 1;
//     // cout << graph[v] << endl;
//     int aux = dfs(graph[v]) + 1;
//     return aux;
// }

int main () {
    int p, n;
    cin >> p;
    n = p/2;
    // for (int i = 0; i < n; i++) {
    //     graph.pb(n + i);
    //     graph.pb(i);
    // }
    // cout << dfs(0) << endl;
    // ll mx = 0;
    // for (int i = 0; i < p; i++) {
    //     if (!marc[i])
    //         mx = max(mx, dfs(i));
    // }
    // cout << mx << endl;

    int i = 2, ans = 1;
    while (i !=1) {
        ans++;
        if(i<=n) i *= 2;
        else i = i-n + i-n-1;
    }
    cout << ans << endl;
    return 0;
}