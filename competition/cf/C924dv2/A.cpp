#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve () {
    ll x,y;
    cin >> x >> y;

    ll m = max(x,y);
    ll n = min(x,y);

    if (((m % 2 == 0 && m/2 == n) && n % 2 == 1 )|| (m == n && n == 1)) {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
}
int main (){
    int nt = 1;
    cin >> nt;
    while(nt--) {
        solve();
    }
    return 0;
}