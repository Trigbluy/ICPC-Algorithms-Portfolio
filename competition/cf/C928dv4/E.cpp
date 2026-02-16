#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll bpow (ll a, int b) {
    if (b == 0) return 1;
    if (b == 1)
        return a;
    if (b%2)
        return bpow(a*a, b/2) *a;
    return bpow(a*a, b/2);
}

void solve () {
    ll n, k;
    cin >> n >> k;

    for (int i = 1; ; i++) {
        int qnt = (n+bpow(2,i-1))/(bpow(2,i));
        if (k <= qnt) {
            cout << bpow(2,i) * k - bpow(2,i-1) << endl;
            return;
        }
        k -= qnt;
    }
}

int main () {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}