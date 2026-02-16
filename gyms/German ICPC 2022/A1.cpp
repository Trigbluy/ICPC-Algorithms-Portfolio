#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    double r;
    cin >> r;
    ll R = (r*100 + 0.5);
    ll mmc = R * 36000 /__gcd(R, (ll)36000);
    ll ans = mmc / R;
    cout << ans << endl;
    return 0;
}