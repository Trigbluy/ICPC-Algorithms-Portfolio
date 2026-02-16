#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e3+100;
int th[NMAX];
int main () {
    int n, q, aux, ans;
    cin >> n >> q;
    ans = n;
    while (q--){
        cin >> aux;
        ans += 2*((th[aux]++) % 2) - 1;
    }
    cout << ans << endl;
    return 0;
}