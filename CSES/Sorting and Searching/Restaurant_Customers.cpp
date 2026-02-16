#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve (){
    int n;
    cin >> n;
    vii arr;
    int a;
    fin(i,0,n){
        fin(j,0,2){
            cin >> a;
            arr.pb({a,j?-1:1});
        }
    }
    sort(arr.begin(), arr.end());
    int ans = 0, att = 0;
    fin(i,0,2*n){
        att += arr[i].s;
        ans = max(ans, att);
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