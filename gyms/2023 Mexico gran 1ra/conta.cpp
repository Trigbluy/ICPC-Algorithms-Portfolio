#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;

const int NMAX = 1e6 + 10;
const ll  M    = 1e9 + 7;

ll exp_bi (ll a, ll b) {
    if (b == 0) return 1;

    if (b == 1)
        return a % M;
    if ( b%2 )
        return (a * (exp_bi(a*a % M, b/2))) % M;
    return exp_bi (a*a % M, b/2) %M;
};
int main () {
    fastio;
    cout << exp_bi(2, M-1);

    return 0;
}