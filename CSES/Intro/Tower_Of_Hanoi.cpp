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
const int NMAX= 1e6+10;
const ll M = 1e9+7;
void move (int from, int to, int aux, int n) {
    if (n == 1) {
        cout << from << ' ' << to << endl;
        return;
    }
    move (from, aux, to, n-1);
    cout << from << ' ' << to << endl;
    move(aux, to, from, n-1);
}
void solve () {
    int n;
    cin >> n;
    cout << (1LL<<n) - 1 << endl;
    move(1,3,2,n);
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();
 
    return 0;
}