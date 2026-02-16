#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector<ll>
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;

ll bpow (ll a, ll b, ll M){
    if(!b) return 1;
    if(b%2) return (a*bpow((a*a)%M,b/2,M))%M;
    return bpow((a*a)%M,b/2,M);
}

void solve() {
    ll j10 = 1, mb, r;
    while(true){
        j10 *= 10;
        cout << "? " << j10 << endl;
        cin >> mb;
        cout << flush;
        if (mb != j10)
            break;
    }

    for (ll k = 10; k >= 1; k--){
        if((j10-mb) % k)
            continue;
        cout << "? " << j10 + (j10-mb)/k << endl;
        cin >> r;
        cout << flush;
        if (r == mb) {
            cout << "! " << (j10-mb)/k << endl;
            return;
        }
    }
    
}
int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}