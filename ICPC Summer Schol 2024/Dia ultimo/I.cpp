#include <bits/stdc++.h>
using namespace std;
#define ll long long
set<ll> primes;
ll n;
void build (ll sz)
{
    for (ll i = 2; i < sz; i++)
    {
        bool isp = true;
        for (auto op : primes)
            if (__gcd(op,i) != 1){
                isp = false;
                break;
            }
        if (isp)
            primes.insert(i);
    }
}

int main ()
{
    cin >> n;
    build(sqrtl(n));
    for (ll i = n;true ; i --)
    {
        bool isp = true;
        for (auto op : primes)
            if (__gcd(op,i) != 1){
                isp = false;
                break;
            }
        if (isp){
            cout << i << endl;
            return 0;
        }
    }

}