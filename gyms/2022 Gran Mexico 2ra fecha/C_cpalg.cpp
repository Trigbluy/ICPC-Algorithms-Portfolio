#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long double ld;
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define LSOne(S) ((S)&-(S))
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
using namespace std;
const ll INF = numeric_limits <ll> :: max() - 1;
vll t, lazy;
int n;

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update (int l, int r, ll x) {
    update(1, 1, n, l, r, x);
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l == tl && tr == r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))+ 
               query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

ll query (int l, int r) {
    return query(1, 1, n, l, r);
}

ll select (ll x) {
    ll l = 0, r = n, m;
    while (l < r){
        m = (l+r+1)/2;
        if (query(0,m) <= x) l = m;
        else r = m - 1;
    }
    return l;
}
void solve () {
    int q;
    cin >> n >> q;
    vll arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    t.assign(4*n, 0);
    lazy.assign(4*n, 0);
    while (q--) {
        vector <pair<ii, int>> upts;
        int k;
        cin >> k;
        int l, r, x;
        while(k--) {
            cin >> l >> r >> x;
            upts.pb({{l,r},x});
            update(l,r,x);
        }
        // cout << "Saiu do While" << endl;
        int sz = query(1,n);
        // cout << "Fez o rsq" << sz << endl;
        if (sz%2) {
            int j = select(sz/2 + 1) - 1;
            cout << arr[j] << endl;
        }
        else {
            int j1 = select(sz/2) - 1;
            int j2 = select(sz/2 + 1) - 1;

            ld aux = arr[j1] + arr[j2]  ;
            cout << aux/2 << endl;
        }
        for (auto p : upts) {
            l = p.f.f;
            r = p.f.s;
            x = p.s;
            update(l,r,-x);
        }
        upts.clear();
    }
}
int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}