//Слава Україні, Героям слава

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(4) << fixed;
    int n;
    cin >> n;
    n *= 2;
    vector<pair<long double, long double>> v(n);
    for(auto &[a, b] : v) cin >> a >> b;
    if(n == 4) {
        cout << 0.0 << "\n";
        return 0;
    }
    vector<vector<long double>> dist(n, vector<long double>(n)), dp(n, vector<long double>(n, -1));
    for(int i = 0; i < n; i++) {
        for(int j = i + 2; j < n; j++) {
            dist[i][j] = dist[j][i] = hypotl(v[i].first - v[j].first, v[i].second - v[j].second);
        }
    }
    function<long double(int, int)> calc = [&](int l, int r) { 
        if(dp[l][r] != -1) return dp[l][r];
        if(r - l + 1 <= 4) return 0.0l;
        long double &ans = dp[l][r];
        ans = numeric_limits<long double>::infinity();
        for(int i = l + 1; i <= r - 2; i += 2) {
            for(int j = i + 1; j <= r - 1; j += 2) {
                ans = min(ans, calc(l, i) + calc(i, j) + calc(j, r) + dist[l][i] + dist[i][j] + dist[j][r]);
            }
        }
        return ans;
    };
    cout << calc(0, n - 1) << "\n";
    return 0;
}