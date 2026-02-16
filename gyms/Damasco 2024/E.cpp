#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define fin(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define f first
#define s second
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
void precalc () {
}
void solve () {
    int n;
    cin >> n;
    vi arr(n);
    fin(i,0,n)
        cin >> arr[i];
    vii opt;
    int g = arr[0], sum = arr[0], mx;
    opt.pb({arr[1],0});
    fin(i,1,n){
        for(ii& op : opt){
            op.f = __gcd(op.f, arr[i]);
            op.s += op.f;
        }
        if (g != __gcd(g,arr[i]))
            opt.pb({g,sum});
        g = __gcd(g, arr[i]);
        if (i == n-1)
            mx = sum;
        sum += g;
    }
    for(ii op : opt)
        mx = max(mx, op.s);
    cout << mx << endl;
}
signed main () {
    fastio;
    precalc();
    int nt = 1;
    // cin >> nt;
    while(nt--)
        solve();
    return 0;
}