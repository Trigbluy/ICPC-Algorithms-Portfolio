#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll n, m , k;
    cin >> n >>  m >> k;
    if (m*k <= n)
        cout << "Iron fist Ketil" << endl;
    else 
        cout << "King Canute" << endl;
    return 0;
}