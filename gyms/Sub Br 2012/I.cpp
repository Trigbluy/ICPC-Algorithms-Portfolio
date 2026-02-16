#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define int ll
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define f first
#define s second
// #define endl '\n'
typedef long long ll;
typedef long double ld;
using namespace std;
int32_t main () {
    fastio;
    int n, m, fin;
    while (cin >> n) {
        cin >> m >> fin;
        fin *= 2;
        vii fun;
        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            fun.pb({x,y});
        }
        sort(fun.begin(), fun.end());
        int mxy = 0;
        vi til;
        for (int i = 0; i < m - 1; i++) {
            int x1 = fun[i].f, y1 = fun[i].s;
            int x2 = fun[i + 1].f, y2 = fun[i + 1].s;

            int mn = y1*(2*(x2-x1) - 1) + y2;
            int mx = y1 + y2*(2*(x2-x1) - 1);
            if (mn > mx) swap(mn,mx);

            mxy += mx - mn;
            fin -= mn;

            til.pb(mx - mn);
        }

        if (fin < 0 || fin > mxy || fin%2) {
            cout << "N" << endl;
            continue;
        }

        vi ans;
        for (int i = m - 2; i >= 0; i--) {
            int x1 = fun[i].f, y1 = fun[i].s;
            int x2 = fun[i + 1].f, y2 = fun[i + 1].s;
            if (fin > 0) {
                if (fin >= til[i]) {
                    fin -= til[i];
                    for (int j = 0; j < x2 - x1 - 1; j++)
                        ans.pb(max(y1, y2));
                }
                else {
                    if (y1 < y2) {
                        for (int j = 0; j < x2 - x1 - 1; j++)
                            if (fin) {
                                ans.pb(min(fin/2,max(y1, y2)));
                                fin -= min(fin,2*max(y1, y2));
                            }
                            else {
                                ans.pb(min(y1,y2));
                            }
                    }
                    else {
                        // cout << x1 << " <-> " << x2 << ": " << fin << endl;
                        fin/=2;
                        for (int j = 0; j < x2 - x1 - 1; j++)
                            if ((fin % (x2 - x1 - 1)) + j  < x2 - x1)
                                ans.pb(fin/(x2-x1-1));
                            else {
                                ans.pb(1 + fin/(x2-x1-1));
                            }
                        fin = 0;
                    }
                }
            }
            else {
                for (int j = 0; j < x2 - x1 - 1; j++)
                    ans.pb(min(y1, y2));
            }
        }

        cout << "S";
        for (int i = ans.size()-1; i >=0; i--)
            cout << ' ' << ans[i];
        cout << endl;
    }
    return 0;
}
