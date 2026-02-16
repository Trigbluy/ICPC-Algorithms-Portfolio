#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < b; i++)
#define f first
#define s second
#define endl '\n'
#define int ll
const signed NMAX = 3*10e5 + 3;
const signed M = 998244353;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<int,int> mpii;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    void init(int na) {
        n=na;
        bit.assign(n, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve(){
    int n;
    vi arr(n), ord(n+3);
    cin >> n;
    fin(i,0,n){
        cin >> arr[i];
        ord[arr[i]] = i;
    }

    FenwickTree ft;
    ft.init(n);
    int ans = 0;
    fin(i,1,n+1){
        int v = ord[i];
        // ans += (ft.sum(0,v) + 1) * (ft.sum(v,n+1));
        // ft.add(v,1);
    }
    cout << ans << endl;
}

signed main (){
    fastio;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}