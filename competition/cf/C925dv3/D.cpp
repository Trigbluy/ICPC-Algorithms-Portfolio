#include <bits/stdc++.h> 
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define ull unsigned ll
#define pb push_back
#define ff first
#define ss second
#define endl '\n'

using namespace std;

const int NMAX = 1e5 + 10;
map <pair<ll,ll>, int> freq;

void solve (){

    int n, x, y;
    cin >> n >> x >> y;
    freq.clear();

    int aux;
    for (int i = 0; i < n ; i++){
        cin >> aux;
        freq[{aux % x, aux % y}]++;
    }

    ull ans = 0;
    for (auto p : freq) {
        ll rx = (x - p.ff.ff) % x;
        ll ry = p.ff.ss;
        ll f = p.ss;

        // if (freq[{rx,ry}])
        //     cout << p.ff.ff << ' ' << p.ff.ss << " with " << rx << ' ' << ry << endl;

        
        if (make_pair(rx,ry) == p.ff)
            ans += (f*(f-1));
        else
            ans += f * freq[{rx,ry}];
    }

    cout << ans/2 << endl;

}

int main (){
    fastio;
    int nt;
    cin >> nt;
    while (nt--){
        solve();
    }
    return 0;
}