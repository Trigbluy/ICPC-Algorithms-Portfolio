#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define vi vector<int>
using namespace std;
void solve() {
    int x, y;
    cin >> x >> y;
    cout << min(x,y) << ' ' << max(x,y) << endl;
}
int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}