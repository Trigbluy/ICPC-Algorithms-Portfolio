#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

ll A,S,L,R;

ll bb (ll l, ll r, ll fn(ll n, ll a1, ll r1),ll a, ll ra) {
    ll m;
    while (l < r){
        // cout << l << ' ' << r << ' ' << m << ' ' << fn(m,a,ra) << endl;
        m = (l+r+1)/2;
        if(fn(m,a,ra)<=0) l = m;
        else r = m-1;
    }
    return l;
}

ll fx (ll n, ll a1, ll r) {
    return n*((n-1)*r + 2*a1)/2 - S;
}

void solve () {
    cin >> A >> S >> L >> R;
    ll ans = (A == S);
    if (A < S)
        for (ll r = 1; r <= R-L; r++)
            for (ll a1 = A; a1 >= L; a1 -= r) {
                ll n = bb (1, 2e5, fx, a1, r);
                if (!fx(n,a1,r) && n != 1)
                    if(A <= (n-1)*r + a1 && (n-1)*r + a1 <= R)
                        ans++;
            }
    cout << ans << endl;
}

int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve ();
    return 0;
}