#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;

vector<int> V;
int n;
void solve () {
    cin >> n;
    int a;
    for (int i = 0 ;i < n ;i ++) {
        cin >> a;
        V.push_back(a);
    }

    int s, t;
    for (int i = 0; i < n - 1; i++) {
        cin >> s >> t;
        int nt = V[i]/s;
        V[i+1] += nt*t;
    }

    cout << V[n-1] << endl;
}
signed main () {
    int n_c = 1;
    while (n_c--) {
        solve();
    }
    return 0;
}