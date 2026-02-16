#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int NMAX = 1e6;
map<ll,ll> dp_;

ll dp (ll n) {
    if (n <= 1) return 0;
    if (dp_[n] != 0)   return dp_[n];

    dp_[n] = dp(n/2) + dp ((n+1)/2) + n;
    return dp_[n];
}

int main () {
    ll x;
    cin >> x;
    cout << dp(x) << endl;
    return 0;
}