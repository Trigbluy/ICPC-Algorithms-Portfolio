#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll ng = (1LL << 61) - 1;
bool psd [100];

void solve () {
    ll n, p, h;
    cin >> n >> p >> h;
    p--; h--;
    for (int i = n-1; i >= 0; i--) {
        // cout << i << ' ' << ((1LL << i)&h) << endl;
        if ((1LL << i)&h) {
            psd[i] = 1;
            h = h^((1LL << (i)) - 1);
        }
    }
    // cout << " ---- " << endl;
    for (int i = 0; i <= n-1; i++) {
        // cout << i << ' ' << (p ^ (1LL << (n-1 - i))) << endl;
        if (psd[i] == 1) {
            if (p & (1LL << (n-1 - i))) {
                cout << "R";
            } else {
                cout << "L";
            }
            p = p^((1LL << (n)) - 1);
        }
        else {
            if (p & (1LL << (n-1 - i))) {
                cout << "L";
            } else {
                cout << "R";
            }
        }
    }
    cout << endl;
}

int main () {
    solve();
    return 0;
}