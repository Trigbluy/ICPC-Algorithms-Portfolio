#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
const int NMAX = 2e5 + 10;
int n, k;
ll aux;
ll val[NMAX], pre[NMAX];
map<ll,ll> dp_[NMAX];

ll dp (int i, ll j)
{
    if (dp_[i][j] != 0LL)
        return dp_[i][j];

    if (j < k){
        int dist = k - j;
        if (dist <= n - i){
            aux = dp(i+dist, k) + pre[i+dist-1] - pre[i-1];
            dp_[i][j] = aux;
        }
        else{
            aux = pre[n] - pre[i-1];
            dp_[i][j] = aux;
        }
        return aux;
    }

    if (i == n)
    {
        dp_[i][j] = 0;
        return 0;
    }
    aux = min (dp(i+1,j+1) + val[i], dp(i+1, j-k));
    dp_[i][j] = aux;
    return aux;
}

int32_t main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1 ; i <= n; i ++)
    {
        cin >> val[i];
        pre[i] = pre[i-1] + val[i];
    }
    cout << dp(1, 0) << endl;
    return 0;
}   