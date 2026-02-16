#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define vi vector<int>
#define pb push_back
#define int ll
using namespace std;
const int NMAX = 1e6 + 10;
const ll M = 1e9 + 7;
int n, l, k;
struct matrix {
    int m[2][2];
    matrix (int a = 0) {
        if(a){
            m[0][0] = m[1][1] = 1;
            m[1][0] = m[0][1] = 0;
        }
        else
            m[0][0] = m[1][1] = m[1][0] = m[0][1] = 0;
    };
    void add_edge (int a, int b, int c = 1) {
        m[a][b] = m[b][a] += c;
    };
    matrix operator* (matrix q){
        matrix aux;
        aux.m[0][0] = (m[0][0]*q.m[0][0] + m[0][1]*q.m[1][0]) % M;
        aux.m[1][0] = (m[1][0]*q.m[0][0] + m[1][1]*q.m[1][0]) % M;
        aux.m[0][1] = (m[0][0]*q.m[0][1] + m[0][1]*q.m[1][1]) % M;
        aux.m[1][1] = (m[1][0]*q.m[0][1] + m[1][1]*q.m[1][1]) % M;
        return aux;
    }
    void print () {
        for (int i = 0; i < 2; i++){
            for (int j = 0 ; j < 2; j++)
                cout << m[i][j] << ' ';
            cout << endl;
        }
    }
};

matrix bpow (matrix a, ll b) {
    //a.print();
    cout << b << endl;
    if (b == 1) return a;
    if (b%2) return (a*bpow((a*a),b/2));
    return bpow((a*a),b/2);
}

matrix bpow2 (matrix a, ll b) {
    matrix resp(1);
    while (b) {
        if(b&1)
            resp = resp*a;
        a = a*a;
        b >>= 1;
    }
    return resp;
}

ll fib (ll a) {
    if (a == 0) return 0;
    if (a == 1) return 1;
    matrix f;
    f.m[0][0] = f.m[1][0] = f.m[0][1] = 1;
    // f.print();
    return bpow2(f, a-1).m[0][0];
}
void solve () {
    cin >> n >> l;
    vi hls;
    hls.pb(-1); hls.pb(n+1);
    int a;
    for (int i = 0; i <l; i++) {
        cin >> a;
        hls.pb(a);
    }
    sort(hls.begin(), hls.end());
    ll ans = 1;
    for (int i = 1; i < hls.size(); i++)
        ans = (ans*fib(hls[i]-hls[i-1]-1))%M;
    cout << ans << endl;
}
int32_t main () {
    fastio;
    // precalc();
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}