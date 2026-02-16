#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector<ll>
#define pb push_back
#define ii pair<int,int>
#define f first
#define s second
typedef long long ll;
using namespace std;
const ll mx = 1e15+100;
vi fb;
void precalc() {
    fb.pb(1), fb.pb(1);
    for (int i = 2; fb[i-1] < mx; i++) {
        fb.pb(fb[i-1] + fb[i-2]);
    }
}
void solve () {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 'B' << endl;
        return;
    }

    string tp;
    while (n!=1) {
        int i;
        for (i = fb.size() - 1; i >= 2; i--) {
            if (n%fb[i]) continue;
            for (int j = 1; j < i; j++)
                // cout << 'A' << endl;
                tp.pb('A');
            tp.pb('B');
            // cout << 'B' << endl;
            break;
        }
        if (fb[i] == 1 || n%fb[i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        n /= fb[i];
    }

    cout << tp << endl;
}

int main () {
    fastio;
    int nt = 1;
    precalc();
    while (nt--)
        solve();
    return 0;
}