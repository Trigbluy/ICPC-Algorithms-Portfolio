#include <bits/stdc++.h>
typedef long long ll;
#define int ll
using namespace std;
const int NMAX = 1e6 + 10;
const ll M = 1e9 + 7;
int n, l, k;
struct matrix {
    int n;
    int m[101][101];
    matrix (int a, int b = 0) {
        n = a;
        for (int i = 0 ; i < n; i++)
            for (int j = 0 ; j < n; j++)
                m[i][j] = 0;
        for (int i = 0 ; i < n; i++)
            m[i][i] = b;
    };
    void add_edge (int a, int b, int c = 1) {
        m[a][b] = m[b][a] += c;
    };
    matrix operator* (matrix q){
        matrix aux(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    aux.m[i][j] = (aux.m[i][j]+((m[i][k]*q.m[k][j]) % M)) % M;
        return aux;
    }
    void print () {
        for (int i = 0; i < n; i++){
            for (int j = 0 ; j < n; j++)
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
    matrix resp(n,1);
    while (b) {
        if(b&1)
            resp = resp*a;
        a = a*a;
        b >>= 1;
    }
    return resp;
}

void solve () {
    cin >> n >> l >> k;
    matrix bs(n);
    int a, b;
    for (int i = 0 ; i < l; i++) {
        cin >> a >> b;
        bs.add_edge(a-1,b-1);
    }
    // bs.print();
    bs = bpow2(bs, k);
    // cout << endl;
    // bs.print();
    int ans = 0;
    for (int i = 0 ; i <n; i++) {
        ans = (ans + bs.m[0][i])%M;
    }
    cout << ans << endl;
}
int32_t main () {
    // precalc();
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}