#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(), cout.tie()
#define frm(i,a,b) for (int i = a; i < b; i++)
#define frl(i,a,b) for (int i = a; i > b; i--)
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define f first
#define s second
typedef long long ll;
using namespace std;
const ll M = 1e9 + 7;
ll bpow (ll a, ll b){
    if (b == 0) return 1LL;
    if (b%2)    return (a*bpow(a*a, b/2)) % M;
    return bpow(a*a % M, b/2);
}
struct mint {
    ll val;
    mint(ll a) {val = (a%M + M)%M;}
    mint operator+ (ll a) {
        return mint(((val + a) % M + M)%M);
    }
    mint operator+ (mint a) {
        return a + val;
    }
    mint operator* (mint a) {
        return mint(((val*a.val) % M + M)%M);
    }
    mint operator/ (mint a) {
        return mint((val*bpow(a.val, M-2)));
    }
    mint operator% (ll a) {
        return mint(val%a);
    }
};

mint func (ll n) {
    mint n3(n%3);
    mint n2((n-1)/2 - (n+3-1)/3);
}
void solve () {

}

int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}