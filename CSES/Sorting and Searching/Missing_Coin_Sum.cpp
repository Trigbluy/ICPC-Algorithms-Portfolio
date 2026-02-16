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
    fin(i,0,n)
        cin >> arr[i];
    ll sum = 0;
    sort(arr.begin(),arr.end());
    fin(i,0,n){
        if(arr[i]> sum + 1){
            cout << sum + 1 << endl;
            return;
        }
        sum += arr[i];
    }
    cout << sum + 1 << endl;
}
int32_t main (){
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}