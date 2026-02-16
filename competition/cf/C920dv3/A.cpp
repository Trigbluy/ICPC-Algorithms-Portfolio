#include <bits/stdc++.h>
using namespace std;

void solve () {
    int a, b, aux;
    cin >> a >> b;
    bool ended = false;
    for (int i = 0; i < 3; i++) {
        cin >> aux;
        if (a == aux) {
            cin >> aux;
            if (!ended) {
                cout << (aux-b)*(aux-b) << endl;
                ended = true;
            }
        }
        else {
            cin >> aux;
        }
    }
}
int main () {
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}