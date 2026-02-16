#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define endl '\n'
const int NMAX = 2e2+10;

using namespace std;
int arr [NMAX];
int dp_ [NMAX][NMAX];
int n;

int dp (int i, int d) {
    if (dp_[i][d] != -1)    return dp_[i][d];

    if (d >= n) return  0;
    if (i > n)  return -2;

    int min = dp(i+1,d);
    if (max(i - arr[i] + 1,1) + d < i) {
        dp_[i][d] = min;
        return dp_[i][d];
    }
}

void solve () {
    cin >> n;
    
    for (int i = 1 ; i <= n; i++)
        cin >> arr[i];
}

int main () {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}