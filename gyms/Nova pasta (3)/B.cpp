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
    return bpow(a%M, M-2);
}
struct mint {
    ll n;
    mint(ll a) : n((a%M + M)%M){};
    mint operator= (ll a) {
        return n = (a%M + M)%M;
    }
    mint operator* (mint a) {
        return mint(((n*a.n)%M + M)%M);
    }
    mint operator/ (mint a) {
        return mint(n*inv(a.n));
    };
    mint operator* (ll a) {
        return mint(((n*a)%M + M)%M);
    }
    mint operator/ (ll a) {
        return mint(n*inv(a));
    };
};

void solve () {
    int n, k;
    cin >> n >> k;
    vll arr(n+2,0);
    for (int i = 1; i <= n ; i++)
        cin >> arr[i];
    map<ll, ll> fq; mint fat = 1;
    for (int i = 1; i <= n; i++) {
        fq[arr[i]]++; fat = fat*i;
    }
    mint ans = 1;
    for (auto p : fq){
        ll sz = p.s;
        for (int i = 1; i <= sz; i++)
            ans = ans*i;
    }
    ans = ans/fat;
    ll a, b; a = b = -1;
    do{
        if (!(a==-1)){
            cin >> a >> b;
            ans = ans/(fq[arr[a]]--);
            arr[a] = b;
            fq[b]++;
            ans = ans*fq[b];
        }
        cout << ans.n << endl;
        a = 0;
    } while (k--);
}
int main () {
    fastio;
    int nt = 1;
    //cin >> nt;
    while (nt--)
        solve();
    return 0;
}