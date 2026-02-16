#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define endl '\n'
#define vi vector<int>
using namespace std;

void solve() {
    string str;
    cin >> str;
    char ant = str[0];
    int ans = 0;
    int inv = 1;
    for (auto c : str) {
        if (c != ant)
        {   
            if (c == '1')
                inv = 0;
            ans++;
        }
        ant = c;
    }
    cout << ans + inv << endl;
}
int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}