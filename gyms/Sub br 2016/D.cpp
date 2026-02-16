#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define maxn 32000
#define f first
#define s second
#define maximum 0x3f3f3f3f

typedef vector<int> vi;

int crivo[maxn];
vi prime, b_div, c_div, d_div;

void compute(){
    for(int i=2;i<maxn;i++){
        if(!crivo[i]){
            for(int j=2;i*j<maxn;j++){
                crivo[i*j] = 1;
            }
        }
    }
    for(int i=2;i<maxn;i++){
        if(!crivo[i]) prime.pb(i);
    }
}

int expo(int a, int b){
    if(b==1) return a;
    if(b%2) return a*expo(a, b-1);
    else{
        int c = expo(a, b/2);
        return c*c;
    }
}

int main () {
    int a, b, c, d, i, j, n, resp = maximum, tk;
    cin >> a >> b >> c >> d;
    compute();
    n = prime.size();
    b /= __gcd(a,b);
    if(b==1 ||(__gcd(a, c)!=a)||(__gcd(c, d)==c)) cout << "-1\n";
    else{
        if(__gcd(a, d)==1){
            if(__gcd(a,b)!=a) cout << a << endl;
            else{
            d /= __gcd(a, d);
            c /= __gcd(a, c);
            b_div = vi(n, 0);
            c_div = vi(n, 0);
            d_div = vi(n, 0);
            for(i=0;i<n;i++){
                for(j=prime[i];!(b%j); j*=prime[i]) b_div[i]++;
                for(j=prime[i];!(c%j); j*=prime[i]) c_div[i]++;
                for(j=prime[i];!(d%j); j*=prime[i]) d_div[i]++;
                tk = expo(prime[i], d_div[i]+1);
                if(c_div[i]>d_div[i] && b!=tk) resp = min(resp, tk);
            }
            if(resp==maximum) cout << "-1" << endl;
            else cout << resp << endl;
            }
        }
        else{
            d /= __gcd(a, d);
            c /= __gcd(a, c);
            b_div = vi(n, 0);
            c_div = vi(n, 0);
            d_div = vi(n, 0);
            for(i=0;i<n;i++){
                for(j=prime[i];!(c%j); j*=prime[i]) c_div[i]++;
                for(j=prime[i];!(d%j); j*=prime[i]) d_div[i]++;
                tk = expo(prime[i], d_div[i]+1);
                if(c_div[i]>d_div[i] && b!=tk) resp = min(resp, tk);
            }
            cout << resp*a << endl;
        }
    }
    return 0;
}