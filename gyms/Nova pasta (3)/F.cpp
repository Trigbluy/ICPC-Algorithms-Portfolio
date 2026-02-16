#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define f first
#define s second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll M = 1e9+7;

ll bpow (ll a, ll b){
    if (b == 0) return 1;
    if(b%2) return (bpow((a*a)%M, b/2)*a)%M;
    return bpow((a*a)%M, b/2);
}
ll inv (ll a){
    return bpow(a%M, M-2); ///
}
struct mint {
    ll n;
    mint(ll a) : n((a%M + M)%M){};
    mint operator= (ll a) {
        return n = (a%M + M)%M;
    }
    mint operator* (mint a) {
        return mint(((n*a.n)%M + M)%M); //
    }
    mint operator/ (mint a) {
        return mint(n*inv(a.n));
    };
    mint operator* (ll a) {
        return mint(((n*a)%M + M)%M); //
    }
    mint operator/ (ll a) {
        return mint(n*inv(a));
    };
    mint operator+ (mint a) {
        return mint(n+a.n);
    }
    mint operator- (mint a) {
        return mint(n-a.n);
    }
};

struct mat {
    mint a11, a12,
         a21, a22;
    mat(): a11(1), a12(0),a21(0),a22(1){};
    mat(mint a, mint b, mint c, mint d) : a11(a), a12(b), a21(c), a22(d){};
    mat operator* (mat m){
        return mat(a11*m.a11 + a12*m.a21,  a11*m.a12 + a12*m.a22,
                   a21*m.a11 + a22*m.a21,  a21*m.a12 + a22*m.a22);
    }
    mat operator- (mat m){
        return mat(a11-m.a11,  a12-m.a12,
                   a21-m.a21,  a22-m.a22);
    }
    mat operator/ (mint a) {
        return mat(a11/a , a12/a, a21/a, a22/a);
    }
    mat operator/ (mat m) {
        return (mat(a11,a12,a21,a22)*mat(m.a22*(-1),m.a12,m.a21,m.a11*(-1)))/(m.a12*m.a21 + m.a11*m.a22*(-1));
    }
    void print () {
        cout << a11.n << ' ' << a12.n << endl;
        cout << a21.n << ' ' << a22.n << endl;
    }
};

mat mbpow (mat a, ll b) {
    if (b == 1) return a;
    if(b%2) return a*mbpow(a*a, b/2);
    return mbpow(a*a, b/2);
}

void solve () {
    ll n, k;
    cin >> n >> k;
    if (n<=2){
        cout << n << endl;
        return;
    }
    mat m(1,1,
          1,0);
    mat mk = mbpow(m, k);
    mk.print();
    mat rint = (mbpow(mk,n-1) - mat())/(mk - mat());
    rint.print();
    cout << (rint.a11.n + rint.a12.n + 1) % M << endl;
}

int main () {
    fastio;
    int nt = 1;
    //cin >> nt;
    while (nt--)
        solve();
    return 0;
}