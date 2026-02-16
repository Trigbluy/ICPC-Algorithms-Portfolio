#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb push_back
#define vi vector<int>
using namespace std;
map<int,bool> poss;
vi A, B, C;

void bruteForce () {
    for (int a : A)
        for (int b : B)
            for (int c : C)
                poss[a+b+c] = true;
}

void solve () {
    int n, m, l, q, aux;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        A.pb(aux);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> aux;
        B.pb(aux);
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> aux;
        C.pb(aux);
    }

    bruteForce();

    
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> aux;
        if (poss[aux])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}