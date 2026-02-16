#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long ll;

int prime[maxn];

void crivo(int n){
    int i, j;
    for(i=2;i<=sqrt(n);i++){
        if(!prime[i]){
            for(j=i;j*i<=sqrt(n);j++){
                prime[i*j] = 1;
            }
        }
    }
}

ll expo(ll a, ll b, ll mod){
    if (b == 0) return 1;
    if (b%2) return (a*expo((a*a) % mod, b/2, mod)) % mod;
    return expo((a*a) % mod, b/2, mod);
}

int main () {
    int n, e, c, i, phi;
    ll d;
    cin >> n >> e >> c;
    crivo(n);
    for(i=3;i<=sqrt(n);i++){
        if((!prime[i]) && (!(n%i)) && (!prime[n/i])){
            phi = (i-1)*((n/i)-1);
        }
    }
    //for(d=2;((d*e)%phi)!=1;d++){}
    //cout << __gcd(e, phi) << endl;
    // d = expo((ll)e, (ll)(phi-3), (ll)phi);
    for (d = 1; ((d*e )% phi) != 1; d = (d*e)%phi);
    //cout << (d*e)%phi << endl;
    cout << expo((ll)c, d, (ll)n) << endl;
    return 0;
}