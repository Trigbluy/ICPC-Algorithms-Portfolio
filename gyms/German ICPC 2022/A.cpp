#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
typedef long double ld;
using namespace std;
bool issqrt (ll a) {
    ll b = sqrtl(a);
    if (b*b == a) return true;
    if((b-1)*(b-1) == a) return true;
    if((b+1)*(b+1) == a) return true;
    return false;
}
void solve() {
    ll a, b;
    cin >> a >> b;
    if (a > b)  swap(a,b);
    ll ans = 1;
    for (ll x = 1; x <= b - 2; x++) {
        if (issqrt((b-1)*(b-1) - x*x))
            if (x*(a-1) % (b-1) == 0)
                if (issqrt((a-1)*(a-1) - ((x*(a-1))/(b-1))*((x*(a-1))/(b-1))))
                    ans ++;
    }
    if(a != b)
        ans *= 2;
    cout << ans << endl;
}
int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}