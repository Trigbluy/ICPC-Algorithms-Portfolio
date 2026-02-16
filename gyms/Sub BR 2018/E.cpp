#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector<int>
#define pb push_back
using namespace std;
const int NMAX = 1e4+100;
bool bulbs[NMAX];
vi   lights[NMAX];
int n, m, l, x, k, y;
void click (int swt) {
    for (int a : lights[swt])
        bulbs[a] = !bulbs[a];
}
bool ver () {
    for (int i = 1; i <= m; i++)
        if (bulbs[i])
            return false;
    return true;
}
int main () {
    fastio;
    cin >> n >> m >> l;
    for (int i = 0 ;i < l; i++){
        cin >> x;
        bulbs[x] = true;
    }
    for (int i = 1 ; i <= n; i++) {
        cin >> k;
        for (int j = 0 ;  j < k; j++) {
            cin >> y;
            lights[i].pb(y);
        }
    }

    for (int i = 0 ; i < 2; i++) {
        for (int swt = 1; swt <= n; swt++) {
            click(swt);
            if (ver()) {
                cout << swt + i*n << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}