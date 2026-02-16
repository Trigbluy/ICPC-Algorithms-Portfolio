#include <bits/stdc++.h>
using namespace std;
void solve () {
    char aux;
    int na = 0, nb = 0;
    for (int i = 0; i < 5; i++) {
        cin >> aux;
        if (aux == 'A') na++;
        else    nb++;
    }

    if (na >= 3)
        cout << 'A' << endl;
    else
        cout << 'B' << endl;
}
signed main () {
    int nt = 1;
    cin >> nt;
    while (nt--)
        solve ();
    return 0;
}