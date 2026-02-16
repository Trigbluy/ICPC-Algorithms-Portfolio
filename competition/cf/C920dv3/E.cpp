#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define endl '\n'
using namespace std;
const int NMAX = 2e5 + 10;

void solve () {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if (xa >= xb) {
        cout << "Draw" << endl;
        return;
    }

    int la, ra, lb, rb;
    int tempo = xb-xa;
    if (tempo%2) {
        la = max (1, ya - (tempo + 1)/2);
        lb = max (1, yb - tempo/2);

        ra = min (w, ya + (tempo + 1)/2);
        rb = min (w, yb + tempo/2);
        if (la <= lb && rb <= ra) {
            cout << "Alice" << endl;
        }
        else {
            cout << "Draw" << endl;
        }
    }
    else {
        la = max (1, ya - (tempo + 1)/2);
        lb = max (1, yb - tempo/2);

        ra = min (w, ya + (tempo + 1)/2);
        rb = min (w, yb + tempo/2);
        if (lb <= la && ra <= rb) {
            cout << "Bob" << endl;
        }
        else {
            cout << "Draw" << endl;
        }
    }
}

int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}