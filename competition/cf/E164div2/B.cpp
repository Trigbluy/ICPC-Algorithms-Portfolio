#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define vi vector<int>
#define pb push_back

using namespace std;
const int INF = numeric_limits<int> :: max();

void solve() {
    int n, base, cnt = 1, aux, min_qnt = INF;
    cin >> n;
    cin >> base;
    for (int i = 0; i < n - 1; i++) {
        cin >> aux;
        if (aux == base)
            cnt++;
        else{
            if (cnt != 0) {
                min_qnt = min(min_qnt, cnt);
                cnt = 0;
            }
        }
    }
    min_qnt = min(min_qnt, cnt);
    if (min_qnt != n)
        cout << min_qnt << endl;
    else
        cout << -1 << endl;
}
int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}