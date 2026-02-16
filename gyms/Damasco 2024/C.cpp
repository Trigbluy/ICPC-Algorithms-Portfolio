#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define fin(i,a,b) for(int i = a; i < b; i++)
// #define endl '\n'
#define pb push_back
#define f first
#define s second
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
void precalc () {}
void solve () {
    int n;
    cin >> n;
    vector <set<int>> graph(n+1);
    vi grau(n+1,0);
    vi onT (n+1,1);
    int a, b;
    // cout << "1d" << endl;
    fin(i,0,n-1){
        cin >> a >> b;
        grau[a]++;
        grau[b]++;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    // cout << "2d" << endl;
    fin(i,1,n+1){
        if (grau[i] >= 4){
            cout << "No" << endl;
            return;
        }

        if (grau[i] == 2){
            a = *graph[i].begin();
            b = *graph[i].rbegin();
            onT[i]=0;
            graph[a].erase(i);
            graph[b].erase(i);
            graph[a].insert(b);
            graph[b].insert(a);
        }
    }
    // cout << "3d" << endl;
    fin(i,1,n+1){
        if (!onT[i]) continue;
        int nv3 = 0;
        for (int viz : graph[i])
            nv3 += (grau[viz] == 3);
        if (nv3 >= 3) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
signed main () {
    fastio;
    precalc();
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}