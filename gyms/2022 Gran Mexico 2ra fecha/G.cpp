#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
using namespace std;

void solve () {
    int n;
    cin >> n;
    ld x, y, c;
    ld sum_c = 0, xm = 0, ym = 0;
    vector <pair<pair<ld,ld>, ld>> pts;
    for (int i = 0 ; i < n ; i++) {
        cin >> x >> y >> c;
        sum_c+= c;
        xm += x*c;
        ym += y*c;
        pts.pb({{x,y},c});
    }

    xm /= sum_c;
    ym /= sum_c;
    ld ans = 0;
    for (int i = 0 ; i < n; i++) {
        ans = max(ans,sqrtl((pts[i].f.f - xm)*(pts[i].f.f - xm) + (pts[i].f.s - ym)*(pts[i].f.s - ym))*pts[i].s);
    }
    cout << fixed << setprecision(7);
    cout << ans << endl;
}
int main () {
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}