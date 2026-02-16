#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back 
typedef long long ll;
#define endl '\n'
#define vi vector<int>
#define vll vector<ll>
using namespace std;

int bb (int x, vll& V) {
    int l = 0, r = V.size() - 1, m;
    while (l < r){
        m = (l+r+1)/2;
        if (x < V[m])
            r = m - 1;
        else
            l = m;
    }
    return l;
}
void solve() {
    vll pos, tm;
    ll n, k, q, d, a, b;
    pos.pb(0);
    tm.pb(0);
    cin >> n >> k >> q;
    for (int i = 0; i < k; i++) {
        cin >> a;
        pos.pb(a);
    }
    for (int i = 0; i < k; i++) {
        cin >> b;
        tm.pb(b);
    }
    while (q--){
        cin >> d;
        int ind = bb(d, pos);
        // cout << '|' <<  d << " e " << ind << " : ";
        if (pos[ind] == d) {
            cout << tm[ind] << ' ';
        }
        else {
            cout << tm[ind] + ((tm[ind+1] - tm[ind])*(d - pos[ind]))/ (pos[ind+1] - pos[ind]) << ' ';
        }
    }
    cout << endl;
}
int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}