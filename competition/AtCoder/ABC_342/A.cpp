#include <bits/stdc++.h>

using namespace std;

void solve () {
    string str;
    cin >> str;
    int  j = 0;
    while (str[j] == str[0]) j++;
    if (j == 1) {
        if (str[0] == str[2])
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
    else {
        cout << j + 1 << endl;
    }
}
signed main () {
    int nt = 1;
    // cin >> nt;
    while(nt--)
        solve ();
    return 0;
}