#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;

struct gp {
    set <ll> ele;
    void add (ll a) {
        ele.insert(a);
    }
    gp operator* (gp& a) {
        gp aux;
        for (ll el : ele)
            for (ll ela : a.ele)
                aux.add(el*ela);
        return aux;
    }
};
void solve() {
    ll n,t;
    gp divs;
    cin >> n >> t;  t--;
    if (!t) {
        cout << n << endl;
        return;
    }
    divs.add(1);
    for (ll i = 2; i*i <= t; i++) {
        if (!(t%i)) {
            int aux = 1;
            gp gaux;
            gaux.add(aux);
            while(!(t%i)) {
                t/=i;
                aux*=i;
                gaux.add(aux);
            }
            divs = divs*gaux;
        }
    }
    if (t != 1) {
        gp aux;
        aux.add(1);
        aux.add(t);
        divs = divs*aux;
    }
    int ans = 0;
    for (ll el : divs.ele)
        if (el <= n)
            ans ++;
        else
            break;
    cout << ans << endl;
}
int main () {
    fastio;
    int nt;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}