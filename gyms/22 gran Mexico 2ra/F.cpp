#include <bits/stdc++.h>
#define fin(i,a,b) for (int i = a; i < (int) b; i++)
#define pb push_back
#define f first
#define s second
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
struct point{
    ii p;
    point(ii a): p(a){};
    point operator-(point a){
        return point({p.f-a.p.f, p.s-a.p.s});
    }
};
int cross (point p1, point p2) {
    return p1.p.f*p2.p.s - p2.p.f*p1.p.s;
}
int32_t main () {
    int n;
    cin >> n;
    vii pts;
    int a, b;
    fin(i,0,n){
        cin >> a >> b;
        pts.pb({a,b});
    }
    ll ans = 0;
    fin (i,0,n)
        fin (j,i+1,n)
            fin (k, j+1, n)
                fin (l, k+1, n){
                    point p1 (pts[i]), p2 (pts[j]),
                       p3 (pts[k]), p4 (pts[l]);
                    if (cross(p3 - p1, p2 - p1) &&
                        cross(p4 - p1, p2 - p1) &&
                        cross(p4 - p1, p3 - p1) &&
                        cross(p4 - p2, p3 - p2))
                        ans++;
                }
    cout << ans << endl;
    return 0;
}