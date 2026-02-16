#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ffr(i,a,b) for(int i = a; i < b; i++)
using namespace std;
void solve() {
    int trees[10][10];
    int n, a, max;
    cin >> n;
    ffr(i,0,n)
        ffr(j,0,n){
            cin >> trees[i][j];
        }
    ffr(j,0,n) {
        a = 1, max = trees[0][j];
        ffr(i,1,n)
            if (trees[i][j] > max) {
                max = trees[i][j];
                a++;
            }
        if (j)
            cout << ' ';
        cout << a;
    }
    cout << endl;
    ffr(i,0,n) {
        a = 1, max = trees[i][0];
        ffr(j,1,n)
            if (trees[i][j] > max) {
                max = trees[i][j];
                a++;
            }
        cout << a << endl;
    }
}
int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}