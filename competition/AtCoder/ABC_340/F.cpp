#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define pb push_back
#define int ll

using namespace std;

const signed NMAX = 2e5+10;

ll gcd (ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1, g;
    g  = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

signed main () {

    ll x, y, a, b, g;

    cin >> a >> b;

    g = gcd(-a, b, x, y);
    
    if (g < 0)
        g = -g;

    swap(x,y);
    
    if (g > 2)
        cout << -1 << endl;
    else if (g == 2) 
        cout << x << ' ' << y << endl;
    else
        cout << 2*x << ' ' << 2*y << endl;

    return 0;
}