#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;

void solve () {
    ll n, x, r, v;
    cin >> n >> x;

    ll ct = 0;

    for (ll k = max(x,2LL); n>= k; k++){
        r = (n-1) % (2*k-2) + 1;
        if (r <= k)
            v = r;
        else
            v = 2*k - r;

        if (v == x)
            ct++;
    }

    cout << ct << endl;
}

int main (){
    int nt = 1;
    cin >> nt;
    while(nt--) {
        solve();
    }
    return 0;
}