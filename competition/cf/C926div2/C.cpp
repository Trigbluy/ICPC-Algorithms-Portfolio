#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
#define ull unsigned ll
#define ld long double
using namespace std;

void solve () {
    ull k, x, a;
    cin >> k >> x >> a;

    ull y, sum;

    sum = 0;
    for (int i = 0; i <= x; i++) {
        y = (sum)/(k-1) + 1;
        sum += y;
    }

    if (a >= sum)
        cout << "YES" << endl;
    else
        cout << "NO"  << endl;
}

int main (){
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}