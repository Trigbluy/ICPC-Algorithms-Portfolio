#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define int ll

using namespace std;

int32_t main () {
    fastio;
    
    int n;
    cin >> n;

    cout << n;

    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3*n + 1;
        cout << " " << n;
    }
    
    cout << endl;
    return 0;
}