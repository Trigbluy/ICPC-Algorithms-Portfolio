#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define endl '\n'
#define vi vector<int>
using namespace std;
const int M = 12;
bool is_left (int a, int b, int x) {
    if (b < a) swap (a, b);
    if (b > x && x > a)
        return true;
    return false;
}
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (is_left(a, b, c) != is_left(a, b, d))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}