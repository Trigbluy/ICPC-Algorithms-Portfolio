#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < b; i++)
#define f first
#define s second
#define endl '\n'
#define int ll
const signed NMAX = 3*10e5+1;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


void solve(){
    int n;
    cin >> n;
    int mi=0,ni=0;
    vi par;
    int a;
    fin(i,0,n){
        cin >> a;
        if (!(a%2))
            par.pb(a);
        else
            mi = max(mi,a), ni++;
    }

    sort(par.rbegin(),par.rend());
    vi sum;
    sum.pb(0);
    fin(i,0,par.size())
        sum.pb(sum[i]+par[i]);

    cout << mi;
    fin(k,2,n+1){
        if (par.size() >= k - 1 && ni)
            cout << ' ' << mi + sum[k-1];
        else if (((k-par.size())%2) && ni)
            cout << ' ' << mi + sum[par.size()];
        else if (!par.empty() && ni && (k-par.size() + 1) <= ni)
            cout << ' ' << mi + sum[par.size()-1];
        else
            cout << ' ' << 0;
    }
    
    cout << endl;
}
signed main (){
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}