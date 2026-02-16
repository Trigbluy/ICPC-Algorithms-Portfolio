#include <bits/stdc++.h>

using namespace std;

const int NMAX = 300010;

int arr[NMAX], dp[NMAX];

int n, m;

int main ()
{
    cin >> n >> m;

    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        arr[i] = a;
    }

    // i <= m -> dp[i] = 0;

    for (int i = m + 1; i <= n; i++)
        dp[i] = max(dp[i-1], arr[i] + dp[i-m]);

    cout << dp[n] << endl;
    
    return 0;
}