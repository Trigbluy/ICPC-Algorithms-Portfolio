#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back 
typedef long long ll;
#define endl '\n'
#define vi vector<int>
#define vll vector<ll>
using namespace std;

void solve() {
    ll r, ans = 0;
    cin >> r;
    for (ll x = r; x > 0; x--) {
        ll ymax = sqrtl((r+1)*(r+1) - x*x);
        if (ymax*ymax + x*x == (r+1)*(r+1))ymax--;
        ll ymin = sqrtl(r*r - x*x);
        if (ymin*ymin + x*x == r*r)ymin--;
        ans += 2*(max(ymax - ymin, 0LL));
    }
    cout << 2*ans << endl;
}
int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}