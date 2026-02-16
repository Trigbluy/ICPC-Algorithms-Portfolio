#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long double ld;
using namespace std;
const int NMAX = 1e6 + 100;
ld dp_[NMAX], pr_[NMAX];
ld dp (int a) {
    if(a < 0) return 0;
    return dp_[a];
}
ld pre (int a) {
    if (a < 0) return 0;
    return pr_[a];
}

void solve () {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        if (a != 0) {
            dp_[i] = 1 + (pre(i - a) - pre(i - b - 1))/(b - a + 1);
            pr_[i] = pre(i-1) + dp(i);
        }
        else {
            dp_[i] = ((ld)(b+1))/b + (pre(i - 1) - pre(i - b - 1))/(b);
            pr_[i] = pre(i-1) + dp(i);
        }
    }
    // printf("%.6f\n", dp(n));
    cout << fixed << setprecision(6) << dp(n) << endl;
}

int main () {
    // fastio;
    solve();
    return 0;
}