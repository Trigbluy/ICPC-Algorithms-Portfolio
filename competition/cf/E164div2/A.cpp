#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 1) {
        cout << "NO" << endl;
        return;
    }

    if ((n + m - 1)/m < n - k)
        cout << "YES" << endl;
    else
        cout << "NO"  << endl;
}
int main () {
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}