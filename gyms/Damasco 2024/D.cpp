#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define fin(i,a,b) for(int i = a; i < b; i++)
using namespace std;
typedef long long ll;
const int NMAX = 1e5+100;
ll dp [NMAX];
bool is_qr (ll n) {
    ll rt = sqrtl(n);
    if (rt*rt == n || (rt + 1)*(rt + 1) == n ||  (rt - 1)*(rt - 1) == n)
        return true;
    return false;
}
void precalc () {
    dp[1] = 1;
    fin(i,2,NMAX){
        dp[i] = dp[i-1];
        if (is_qr(i))
            dp[i]+=1;
        else
            dp[i]+= i-1;
        int rt = sqrtl(i);
        dp[i] += i - rt;
    }
}
void solve () {
    int n;
    cin >> n;
    cout << dp[n] << endl;
}
int main () {
    fastio;
    precalc();
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}