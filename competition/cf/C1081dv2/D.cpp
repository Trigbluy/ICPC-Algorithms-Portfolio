// Uncomplete
#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fin(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
#define f first
#define s second
#define endl '\n'
const int NMAX = 1e5+3;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
vi tree[NMAX];
int h[NMAX], pai[NMAX], prof[NMAX], arr[NMAX];
ii vv[NMAX];
int val[NMAX];
ii most_deep[NMAX]; // {most, second}
int dfs1 (int v = 1, int p = -1) {
    pai[v] = p;
    int pro = h[v];
    int sum = 0;
    int val = 0;
    most_deep[v] = {0,0};
    for (int viz : tree[v]){
        if (viz == p) continue;
        h[viz] = h[v] + 1;
        pro = max(pro, dfs1(viz,v));
        sum += vv[viz].s;
        val += vv[viz].f;

        if (prof[viz] > prof[most_deep[v].f]) {
            swap(most_deep[v].f, most_deep[v].s);
            most_deep[v].f = viz;
        } else if (prof[viz] > prof[most_deep[v].s])
            most_deep[v].s = viz;
    }
    vv[v] = {val+sum, sum + arr[v]};
    return prof[v] = pro;
}

int dfs2 (int v = 1, int p = -1) {
    // cout << "Doing " << v << " {" << most_deep[v].f << "," << most_deep[v].s << "}"<< endl;
    ll vl = 0;
    for (int viz : tree[v]){
        if (viz == p) continue;
        dfs2(viz, v);
        if ((tree[v].size() == 2) || ((tree[v].size() == 1) && v == 1))
            vl = val[viz];
        else {
            if (viz != most_deep[v].f) {
                ll aux = vv[viz].s * (prof[most_deep[v].f] - h[v]);
                if (vl < aux){
                    vl = max(vl, aux);
                }
            }
            if (viz != most_deep[v].s) {
                ll aux = vv[viz].s * (prof[most_deep[v].s] - h[v]);
                if (vl < aux){
                    vl = max(vl, aux);
                }
            }
        }
    }
    return val[v] = vl;
}
void solve () {
    int n;
    cin >> n;
    fin(i,1,n+1){
        cin >> arr[i];
        tree[i].clear();
    }
    int a, b;
    fin(i,1,n){
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfs1();
    dfs2();

    fin(i,1,n+1)
        cout << vv[i].f + val[i] << ' ';
    cout << endl;
}

int main () {
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}