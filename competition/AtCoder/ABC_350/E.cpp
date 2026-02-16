#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pb push_back
#define vi vector<int>
typedef long long ll;
typedef long double ld;
using namespace std;
const int NMAX = 2e5+100;
map<ll, ld> dp_;
ll x, y, a;
ld dp (ll n) {
    if (n <= 0) return 0;
    if (dp_.find(n) != dp_.end())   return dp_[n];

    ld dpa = dp(n/a) + x;
    ld dpb = y;
    for (int i = 2; i <= 6; i++)
        dpb += dp(n/i) + y;
    dpb /= 5;
    ld ans = min(dpa, dpb);
    
    dp_[n] = ans;
    return ans;
}

int main () {
    fastio;
    ll n;
    cin >> n >> a >> x >> y;
    ld aux = dp(n);
    cout << fixed << setprecision(8) << aux << endl;
    return 0;
}