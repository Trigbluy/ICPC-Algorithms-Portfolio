#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ff first
#define ss second
#define ll long long
// #define int ll
#define ld long double
#define ull unsigned ll
#define endl '\n'
using namespace std;

const int NMAX = 5e2 + 10;

set<int> invr;

void solve () {
    int n, q;

    cin >> n >> q;

    char ant, aux;
    cin >> ant;

    for (int i = 2; i <= n; i++) {
        cin >> aux;
        if (aux == ant)
            invr.insert(i);
        ant = aux;
    }

    int ind, l, r;
    for (int i = 0; i < q; i++) {
        cin >> ind >> l >> r;
        if (ind == 1) {
            if (l != 1)
                if (invr.find(l) != invr.end())
                    invr.erase(l);
                else
                    invr.insert(l);

            if (r != n)
                if (invr.find(r+1) != invr.end())
                    invr.erase(r+1);
                else
                    invr.insert(r+1);
        }
        else {
            auto lb = invr.lower_bound(l+1);
            if (lb == invr.end() || r < *lb)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}

signed main () {
    fastio;
    int n_c = 1;
    while (n_c--) {
        solve();
    }
    return 0;
}