#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ffr(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define f first
#define s second
// typedef vector<int> vi;
// typedef vector<ii> vii;
// typedef pair<int,int> ii;
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
using namespace std;
const int INF = numeric_limits<int> :: max();
const int NMAX = 2e3;
void solve() {
    int n;
    cin >> n;
    vi arr(n);
    vii dp(n);
    ffr(i,0,n)
        cin >> arr[i];
    if (arr[0] == 0) {
        dp[0] = {0,0};
    }
    else if (arr[0] == 1) {
        dp[0] = {1,1};
    }
    else if (arr[0] >= 2) {
        dp[0] = {1, 2};
    }
    ffr(i,1,n){
        int qnt = arr[i] + (dp[i-1].s >= 2);
        dp[i] = {dp[i-1].f, 0};
        if (qnt && !dp[i-1].s) {
            qnt--;
            dp[i].f++;
            dp[i].s = 1;
        }
        if (qnt)
            dp[i].f++;
        dp[i].s = qnt;
    }
    cout << dp[n-1].f << endl;
}
int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}