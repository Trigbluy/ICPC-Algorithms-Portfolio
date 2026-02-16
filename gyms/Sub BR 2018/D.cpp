#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;
int main () {
    fastio;
    int n, ans = 0, aux;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        ans += aux != 1;
    }

    cout << ans << endl;
    return 0;
}