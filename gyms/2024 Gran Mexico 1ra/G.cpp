#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(), cout.tie()
#define frm(i,a,b) for (int i = a; i < b; i++)
#define frl(i,a,b) for (int i = a; i > b; i--)
#define pb push_back
#define vi vector<int>
using namespace std;

void solve () {
    int n, a;
    vi towers;
    cin >> n;
    frm(i,0,n){
        cin >> a;
        towers.pb(a);
    }
    sort(towers.begin(), towers.end());
    int max_tower = *towers.rbegin();
    vi dp(max_tower + 10, 0);
    frl(i, max_tower - 1, -1) {
        int rest = (*upper_bound(towers.begin(), towers.end(), i)) - i;
        if (rest == 1)
            dp[i] = !dp[i+1];
        else
            dp[i] = true;
    }
    if (dp[0])
        cout << "Alicius" << endl;
    else
        cout << "Bobius" << endl;
}
int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}