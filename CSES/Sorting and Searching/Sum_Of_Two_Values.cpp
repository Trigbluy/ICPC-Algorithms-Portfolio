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
void solve (){
    ll n, x;
    cin >> n >> x;
    vi arr(n);
    map<int,int> mp;
    map<int,vi> ind;
    fin(i,0,n){
        cin >> arr[i];
        mp[arr[i]]++;
        ind[arr[i]].pb(i+1);
    }
    fin(i,0,n){
        if(x == 2*arr[i]){
            if(mp[arr[i]] <= 1) continue;
            cout << ind[arr[i]][0] << ' ' << ind[arr[i]][1] << endl;
            return;
        }
        else{
            if(!mp[x-arr[i]]) continue;
            cout << ind[arr[i]][0] << ' ' << ind[x-arr[i]][0] << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
int32_t main (){
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}