#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector<ll>
#define pb push_back
#define ii pair<ll,ll>
#define f first
#define s second
typedef long long ll;
using namespace std;
map<int,int> pos[2];
void solve () {
    ll b, n;
    cin >> b >> n;
    ll r = 0, a;
    ii mx[2] = {{-1, -1},{-1,-1}};

    vi nm;
    for (int i = 0 ; i<n; i++) {
        cin >> a;
        nm.pb(a);
    }
    reverse(nm.begin(), nm.end());
    int i;
    for (i = 0; i < n; i++) {
        a = nm[i];
        pos[i%2][a] = i;
        if (i%2 == 0)
            r += a;
        else
            r -= a;
    }

    r = (r%(b+1) + b+1)%(b+1);

    if (r == 0) {
        cout << "0 0\n";
        return;
    }

    for (ii p : pos[0])
        if (r <= p.f && mx[0].s < p.s)
            mx[0] = p;

    for (ii p : pos[1])
        if ( r + p.f  >= b+1 && mx[1].s < p.s)
            mx[1] = p;
    
    // cout << r << ' ' << mx[0].s << ' ' << mx[1].s << endl;
    if (mx[0].f == -1 && mx[1].f == -1){
        cout << "-1 -1\n";
        return;
    }

    if ((mx[0].s != -1 && mx[0].s > mx[1].s)) {
        cout << n - mx[0].s << ' ' << mx[0].f - r  << endl;
        return;
    }
    
    cout << n - mx[1].s << ' ' << mx[1].f + r - b - 1 << endl;
}

int main () {
    fastio;
    int nt = 1;
    // precalc();
    while (nt--)
        solve();
    return 0;
}