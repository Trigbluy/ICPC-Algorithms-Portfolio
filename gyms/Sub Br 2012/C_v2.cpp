#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define vi vector<int>
typedef long long ll;
#define maxn 10006
using namespace std;

typedef vector<ll> vl;
vl new_dp(maxn), old_dp(maxn), pre(maxn);

int main () {
    fastio;
    int n, i, tam;
    ll tot;
    while (cin >> n) {
        for(i=1;i<=n;i++){
            cin >> old_dp[i];
            pre[i] = pre[i-1]+old_dp[i];
        }
        for(tam=2;tam<=n;tam++){
            for(i=1;i+tam-1<=n;i++){
                tot = pre[i+tam-1]-pre[i-1];
                new_dp[i] = max(tot-old_dp[i], tot-old_dp[i+1]);
            }
            old_dp = new_dp;
        }
        cout << new_dp[1] << endl;
    }
    return 0;
}