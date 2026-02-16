#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
// #define int ll
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
// #define endl '\n'
using namespace std;
const int NMAX= 1e6+10;
const ll M = 1e9+7;
void solve () {
    ll q, a, b;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        if (a > b) swap(a,b);
        if (a >= b-a && !((2*a-b)%3))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();
 
    return 0;
