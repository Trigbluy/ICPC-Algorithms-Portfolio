#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define int ll
#define pb push_back
#define ff first
#define ss second

using namespace std;

void solve () {
    char ant;
    char aux;
    int mx, cont;
    mx = 0, cont = 0;
    cin >> aux;
    ant = aux;
    cont ++;
    while (cin >> aux) {
        if (aux == ant) {
            cont++;
        } else {
            mx = max (mx, cont);
            cont = 1;
            ant = aux;
        }
    }
    cout << max(mx, cont) << endl;
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();

    return 0;
}