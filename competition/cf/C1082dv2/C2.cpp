#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fin(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
#define f first
#define s second
#define endl '\n'
#define int long long
const int NMAX = 3e5+3;
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef struct element {
    int val;
    int pre, pos;
} ele;
vector<ele> els;
int n;
vi who_i_eli [NMAX];

void eliminate(int v, int frm) {
    int a, b;
    b = els[ els[v].pre ].pos = els[v].pos;
    who_i_eli[frm].pb(v);
    //cout << frm << " eliminate " << v << endl;
    if (els[v].pos == -1)
        return;
    a = els[ els[v].pos ].pre = els[v].pre;
    if (els[a].val + 1 == els[b].val)
        eliminate(b,frm);
}

void solve () {
    cin >> n;
    ele b;
    els.clear();
    els.assign(n,b);
    fin(i,0,n){
        cin >> els[i].val;
        els[i].pre = i-1;
        els[i].pos = i+1;
        who_i_eli[i].clear();
    }
    els[0].pre = -1;
    els[n-1].pos = -1;
    
    for (int i = n-1; i>0; i--)
        if (els[i].val == els[ els[i].pre ].val + 1)
            eliminate (i, i-1);

    int ans = 0;
    int sum = 0;
    for(int i = n-1; i>=0; i--){
        sum += n-i;
        // cout << i << ": " << ans << ' ' << sum << endl;
        for (int j : who_i_eli[i])
            sum -= (n-j);
        // cout << "used in j = " << j << endl;
        // cout << sum << endl;
        ans += sum;
    }
    cout << ans << endl;
}

int32_t main () {
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}