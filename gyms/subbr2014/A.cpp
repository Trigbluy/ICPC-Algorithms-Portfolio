#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main () {
    ll x, y, t;
    cin >> x >> y;
    if (y < x) swap(x,y);
    t = ((x*y) + (y - x - 1))/(y-x);
    cout << (t + x-1)/x << endl;
    return 0;
}