#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fin(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
#define f first
#define s second
#define endl '\n'
#define int long long
const int NMAX = 1e5+3;
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

void eliminate(int v) {
    n--;
    int a, b;
    b = els[ els[v].pre ].pos = els[v].pos;
    if (els[v].pos == -1)
        return;
    a = els[ els[v].pos ].pre = els[v].pre;
    if (els[a].val + 1 == els[b].val)
        eliminate(b);
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
    }
    els[0].pre = -1;
    els[n-1].pos = -1;
    
    for (int i = n-1; i>0; i--)
        if (els[i].val == els[ els[i].pre ].val + 1)
            eliminate (i);
    cout << n << endl;
}

int32_t main () {
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}