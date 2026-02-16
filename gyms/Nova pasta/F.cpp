#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector<int>
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int NMAX = 7e3;
const ll  M    = 1e9 + 7;
ull dp [NMAX][NMAX]; // dp[i][j] eh rampa de comprimento i e j blocos

void solve () {
    ll s, b;
    cin >> s >> b;
    dp[0][0] = 1;
    for (int i = 0; i <= b; i++)
        dp[1][i] = dp[i][0] = 1;

    for (int i = 2; i <= b; i++)
        for (int j = i; j <= s; j++)
            for (int k = 0; k <= j/i + 1; k++)
                if (j-k*i >= 0)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k*i]) % M;
                else
                    break;
    ll ans = (s*s == b || s == 1) ? M - 1 : 0;
    b -= s;
    for (int i = 0; i <= s; i++)
        for (int j = 0; j <= b; j++)
            ans = (ans + (dp[i][j]*dp[s-i][b-j]) % M) % M;
    cout << ans << endl;
}

int main(){
    fastio;
    solve();
    return (0);
}