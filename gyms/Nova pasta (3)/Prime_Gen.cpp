#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main () {
    FILE *out = fopen("primes.txt", "w");
    vll primes;
    primes.pb(3);
    for (ll i = 5;i <= 3e5; i+=2){
        bool pr = true;
        for (ll r = 0; primes[r]*primes[r] <= i && r < primes.size(); r++)
            if (!i%primes[r]){
                pr = false;
                break;
            }
        if(pr){
            primes.pb(i);
        }
    }
    int sz = primes.size();
    for (ll i = 3e9+1;primes.size() <= sz + 1e2; i+=2){
        bool pr = true;
        for (ll r = 0; primes[r]*primes[r] <= i && r < primes.size(); r++)
            if (!(i%primes[r])){
                pr = false;
                break;
            }
        if(pr){
            primes.pb(i);
            fprintf(out, "%lld\n", i);
        }
    }
    fclose(out);
    return 0;
}