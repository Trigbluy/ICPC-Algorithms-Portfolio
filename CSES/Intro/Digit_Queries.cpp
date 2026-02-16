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
#define endl '\n'
using namespace std;
typedef vector<ll> vll;
const int NMAX= 1e6+10;
const ll M = 1e9+7;

void solve () {
    int q; cin >> q;
    while (q--) {
        ll k; cin >> k; k--;
    // ll a , b;
    // cin >> a >> b;
    // for (int k = a; k <= b; k++) {
        ll acm = 0, b10 = 10, nd = 1;
        for (int i = 0; i < 18 && (acm + nd*(b10-b10/10) <= k); i++){
            acm += nd*(b10-b10/10);
            b10 *= 10;
            nd++;
        }
        // if (9 >= k) nd--;
        // cout << acm <<' ' << b10 <<' ' << nd << ' ' << endl;
        ll dif = k - acm;
        ll n = (b10/10) + dif/nd;
        // cout << dif << ' ' << n << endl;
        for (int i = 1; i < nd - ((dif) % nd); i++)
            n/=10;
        cout << n % 10 << endl;
        // cout << "----------" << endl;
    }
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();

    return 0;
}