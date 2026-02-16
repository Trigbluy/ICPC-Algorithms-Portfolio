#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define int ll
using namespace std;
const signed NMAX_ = 1e6;
vector<ll> boxa, boxb;
int n,m;
ll lztree[NMAX_];

void build (int v, int l, int r){
    if (l == r) {
        lztree[v] = boxa[l];
        return;
    }
    int m = (l+r)/2;
    build (2*v, l, m);
    build (2*v+1, m + 1, r);
}
void build (){
    build(1, 0, n-1);
}

void addSeg (int v, int l1, int r1, int l2, int r2, ll val){  // l1,r1 -> Atual     l2,r2 -> Para adicionar
    if (r1 < l2 || l1 > r2) return;
    if (l2 <= l1 && r1 <= r2) {
        lztree[v] += val;
        return;
    }

    int m = (l1 + r1)/2;
    addSeg(2*v    , l1   , m , l2, r2, val);
    addSeg(2*v + 1, m + 1, r1, l2, r2, val);
}
void addSeg (int l, int r, ll val){
    addSeg(1, 0, n-1, l, r, val);
}

ll lz (int v, int l, int r, int node, ll val) {
    if (node < l || node > r){
        lztree[v] += val;
        return -1;
    }

    if (l == r){
        lztree[v] += val;
        return lztree[v];
    }

    int m = (l+r)/2;
    ll nval = val + lztree[v];
    lztree[v] = 0;
    if (node <= m){
        lz(2*v + 1, m + 1, r, node, nval);
        return lz(2*v, l, m, node ,nval);
    }

    lz(2*v, l, m, node ,nval);
    return lz(2*v + 1, m + 1, r, node, nval);
}
ll lz (int node){
    return lz (1, 0, n-1, node, 0);
}

signed main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int aux;
    for (int i = 0; i < n;i ++) {
        cin >> aux;
        boxa.pb(aux);
    }

    for (int i = 0 ; i < m ; i ++) {
        cin >> aux;
        boxb.pb(aux);
    }

    build();

    for (int box : boxb) {
        ll n_b  = lz(box);
        ll fall = n_b/n;
        ll r    = n_b % n;

        addSeg(box, box, - n_b);
        addSeg(0, n-1, fall);
        addSeg(box + 1, min (n-1, box + r), 1);
        if (box + r >= n)
            addSeg(0, box+r - n, 1);
    }

    for (int i = 0 ; i < n; i++)
        cout << lz(i) << endl;

    return 0;
}