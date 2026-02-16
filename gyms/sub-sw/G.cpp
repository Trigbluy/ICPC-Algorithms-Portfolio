#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int ll
#define ff first
#define ss second
#define fastio ios_base :: sync_with_stdio (false), cin.tie (0), cout.tie (0);

const ll M1 = 1e9 + 7;
const ll M2 = 1e9 + 9;

using namespace std;
set <pair<ll,ll>> tp;

signed main (){
    fastio;

    ll d;
    cin >> d;

    for (ll a = 1; a*a <= 2*d; a++){
        if ( ( (2*d) % a ) == 0) {
            ll b = (2*d)/a;

            if (a%2 == b%2) continue;
            
            ll m = ( a+b-1)/2;
            ll n = (-a+b-1)/2;

            if (m <= 0 || n <= 0) continue;
            
            tp.insert({n,m});
        }
    }

    cout << tp.size() << endl;
    for (auto p : tp){
        cout << p.ff << ' ' << p.ss << endl;
    }

    return 0;
}