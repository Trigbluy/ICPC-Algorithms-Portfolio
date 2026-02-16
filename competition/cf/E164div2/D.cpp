#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ff first
#define ss second
#define vi vector<int>
#define pb push_back
typedef long long ll;

using namespace std;
const int INF  = numeric_limits<int> :: max();
const int NMAX = 5e3 + 100;
const int M    = 998244353;

map <pair<int,int>, ll> freq;

void solve() {
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    for (int val : arr) {
        auto aux = freq;
        for (auto el : aux) {
            ll nt = el.ff.ff;
            ll n1 = el.ff.ss;
            ll fr  = el.ss;
            
            if (val >= 2*nt - n1)
                freq[{val, val-(2*nt-n1)}] = (freq[{val, val-(2*nt-n1)}] + fr) % M;
            else if (val <= n1)
                freq[{nt, n1-val}] = (freq[{nt, n1-val}] + fr) % M;
            else
                freq[{(2*nt-n1 + val + 1)/2, (2*nt-n1 + val)%2}] = (freq[{(2*nt-n1 + val + 1)/2, (2*nt-n1 + val)%2}] + fr) % M;
        }

        freq[{val, val}]++;
    }

    ll ans = 0;
    for (auto p : freq) {
        ans = (ans + p.ff.ff*p.ss) % M;
    }

    cout << ans << endl;
}

int main () {
    fastio;
    int nt = 1;
    // cin >> nt;
    while(nt--)
        solve();
    return 0;
}