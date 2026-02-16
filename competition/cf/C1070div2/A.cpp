#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin(i,a,b) for(int i = a; i < b; i++)
typedef vector<int> vi;
void solve(){
    int n, a, max = -1;;
    int ans = 0;
    vi arr;
    cin >> n;
    fin(i,0,n){
        cin >> a;
        arr.pb(a);
        if (a >= max)
            swap(a,max);
        else
            ans++;
    }
    cout << ans << endl;
}
signed main (){
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}