#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
void solve (){
    int n;
    cin >> n;
    vll arr(n);
    ll ans, att = 0;
    fin(i,0,n){
        cin >> arr[i];
        att += arr[i];
    }
    sort(arr.begin(),arr.end());
    int med = arr[0];
    att-= n*med, ans = att;
    fin(i,1,n){
        if(arr[i] == med) continue;
        att += (arr[i] - med)*(2*i-n);
        ans = min(ans,att);
        med = arr[i];
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