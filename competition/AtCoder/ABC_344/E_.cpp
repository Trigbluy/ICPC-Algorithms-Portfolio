#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
using namespace std;

list <int> seq;

int main () {
    fastio;
    int n, q, aux;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        seq.pb(aux);
    }   

    cin >> q;
    int qr, x, y;
    while (q--) {
        cin >> qr >> x;
        if (qr == 1) {
            cin >> y;
            
        }
    }
}