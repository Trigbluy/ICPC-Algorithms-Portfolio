#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main () {
    ll n, t1, i;
    cin >> n;
    for (i = 1, t1=10; i <= 10; i++, t1 *= 10){
        if ((t1 - 1)/9 > n)
            break;
    }
    i--, t1/=10;
    t1 = (t1 - 1)/9;
    ll j = 1;
    while(t1*j<=n)j++;
    j--;
    // cout << i << ' ' << j << ' ' << t1 << endl;
    int ans = 0;
    for (int a = 0; a <= 9; a++) {
        if (a <= j && a != 0)
            ans += i;
        else
            ans += i-1;
    }
    if (n >= (9*t1 + 1) || n < 10)
        ans++;
    cout << ans << endl;
    return 0;
}