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
    int a,b;
    fin(i,0,n){
        cin >> a >> b;
        arr.pb({b,a});
    }
    sort(arr.begin(),arr.end());
    int t = arr[0].f, ans = 1;;
    fin(i,1,n){
        if(t > arr[i].s) continue;
        t = arr[i].f; ans++;
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