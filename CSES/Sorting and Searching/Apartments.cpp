#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
void solve (){
    int n, m, k;
    cin >> n >> m >> k;
    vi pp, ap;
    int a;
    fin(i,0,n) {
        cin >> a;
        pp.pb(a);
    }
    fin(i,0,m){
        cin >> a;
        ap.pb(a);
    }
    sort(pp.begin(), pp.end());
    sort(ap.begin(), ap.end());
    int ind = 0, ans = 0;
    fin(i,0,n){
        while(ind < m && pp[i] > ap[ind]+k) ind++;
        if(ind >= m) break;
        if(pp[i] < ap[ind]-k) continue;
        ans++; ind++;
    }
    cout << ans << endl;
}
int32_t main (){
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}