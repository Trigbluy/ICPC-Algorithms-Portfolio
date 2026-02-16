#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pb push_back
#define vi vector<int>
typedef long long ll;
typedef long double ld;
using namespace std;

ll dp_ [100100];

ll fibo (ll n) {
    if (dp_[n] != 0) return dp_[n];
    
    dp_[n] = (fibo(n-1) + fibo(n-2)) % 19239214LL;
    return dp_[n];
}

int main () {
    fastio;
    dp_[1] = 1;
    dp_[2] = 1;
    cout << fibo(1000) << endl;
    return 0;
}