#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
const int  NMAX = 1e4 + 100;
ll dp_[NMAX][NMAX], arr[NMAX], pre[NMAX];
bool calc[NMAX][NMAX];

ll dp (int i, int j) {
    if (calc[i][j]) return dp_[i][j];
    if (i > j) return 0LL;
    if (i == j) return arr[i];
    ll ans = pre[j] - pre[i-1] - dp(i+1, j);
    ans = max(ans, pre[j] - pre[i-1] - dp(i,j-1));
    calc[i][j] = true;
    return dp_[i][j] = ans;
}
int main () {
    fastio;
    int n;
    while (cin >> n){
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            pre[i] = pre[i-1] + arr[i];
            for (int j = i; j <= n; j++)
                calc[i][j] = false;
        }
        cout << dp(1, n) << endl;
    }
    return 0;
}
