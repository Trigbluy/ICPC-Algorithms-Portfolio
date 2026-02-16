#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
typedef long double ld;
using namespace std;
struct mat {
    ld x11, x12,
       x21, x22;
    mat(ld a = 1, ld b = 0, ld c = 0, ld d = 1) : x11(a), x12(b), x21(c), x22(d){}
    mat operator* (mat a) {
        return mat (x11*a.x11 + x12*a.x21, x11*a.x12 + x12*a.x22,
                    x21*a.x11 + x22*a.x21, x21*a.x12 + x22*a.x22);
    }
};
mat bpow (mat a, ll b) {
    if(!b) return mat();
    if(b%2) return a*bpow(a*a, b/2);
    return bpow(a*a, b/2);
}
void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "100 0" << endl;
        return;
    }
    mat B = mat(0.5, 0.5,
                1  , 0  );
    mat Bn = bpow(B, n-2);
    ld ans = 100 * Bn.x12;
    cout << fixed << setprecision(7) << ans << ' ' << 100-ans << endl;
}
int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}