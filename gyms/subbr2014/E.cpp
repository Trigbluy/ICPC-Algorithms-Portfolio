#include <bits/stdc++.h>
typedef long long ll;
#define f first
#define s second
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
using namespace std;
const int NMAX = 1e2;
int n, m;
int dp[NMAX][NMAX][11];
int grid[NMAX][NMAX];
vector<pair<int,ii>> ts;
int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            ts.pb({grid[i][j], {i,j}});
        }
    sort(ts.begin(), ts.end());
    for(auto t : ts) {
        int i, j;
        i = t.s.f;
        j = t.s.s;

        dp[i][j][1] = t.f;
        // cout << "Setting " << i << ", " << j << " - " << 1 << " to " << t.f << endl;
        for (int k = 2; k <= 10; k++) {
            int mx = 0;
            for (int a = 0; a < k; a++)
                for (int b = 0; a + b < k; b++)
                    for (int c = 0; a + b + c < k; c++){
                        int d = k - a - b - c - 1;
                        
                        int sum = dp[i][j][1];

                        sum += dp[i+1][j][a];
                        sum += dp[i-1][j][b];
                        sum += dp[i][j+1][c];
                        sum += dp[i][j-1][d];

                        mx = max(mx, sum);
                    }
            dp[i][j][k] = mx;
            // cout << "Setting " << i << ", " << j << " - " << k << " to " << mx << endl;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans = max(ans, dp[i][j][m]);
    cout << ans << endl;
    return 0;
}