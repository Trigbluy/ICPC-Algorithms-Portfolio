#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define ii pair<ll,ll>
#define lll pair<ll,ii>
#define f first
#define s second
using namespace std;
const int NMAX = 1e5;
ll pw[550][3];
ll eq[550][4];
map<lll, int> mp;
void precalc () {
    pw[0][0] = pw[0][1] = pw[0][2] = 1;
    for (int i = 1; i <= 510; i++) {
        // cout << pw[i-1][0] << ' ';
        pw[i][0] = (pw[i-1][0]*2) % ((ll)1e9+7);
        pw[i][1] = (pw[i-1][1]*3) % ((ll)1e9+9);
        pw[i][2] = (pw[i-1][2]*37) % ((ll)1e9+1);
    }
    // cout << endl;
}
int main () {
    fastio;
    precalc();
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < 4 ;j++)
            cin >> eq[i][j];
    ll x, y, z;
    for (int i = 0 ; i < n; i++) {
        cin >> x >> y >> z;
        lll aux = {0,{0,0}};
        for (int j = 0 ; j < m; j++) {
            if ((eq[j][0]*x + eq[j][1]*y + eq[j][2]*z - eq[j][3]) > 0) {
                aux.f   = (aux.f   + pw[j][0]) % ((ll)(1e9+7));
                aux.s.f = (aux.s.f + pw[j][1]) % ((ll)(1e9+9));
                aux.s.s = (aux.s.s + pw[j][2]) % ((ll)(1e9+1));
            }
        }
        // cout << aux.first << ' ' <<  aux.second.first << ' ' <<   aux.second.second << endl;
        mp[aux]++;
    }
    int ans = 0;
    for (auto p : mp)
        ans = max(ans, p.second);
    cout << ans << endl;
    return 0;
}