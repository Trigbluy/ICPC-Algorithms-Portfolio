#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define endl '\n'
#define all(v) v.begin(),v.end()
using namespace std;
const int NMAX = 1e5 + 10;
struct Point {
    int x,y;
    Point operator +(Point& a) {
        return {x + a.x, y + a.y};
    }
    Point operator -(Point& a) {
        return {x - a.x, y - a.y};
    }
};
typedef Point P;
vector<array<int, 3>> manhattanMST(vector<P> ps) {
	vi id(ps.size());
	iota(all(id), 0);
	vector<array<int, 3>> edges;
	for(int k = 0; k < 4; k++) {
		sort(all(id), [&](int i, int j) {
		     return (ps[i]-ps[j]).x < (ps[j]-ps[i]).y;});
		map<int, int> sweep;
		for (int i : id) {
			for (auto it = sweep.lower_bound(-ps[i].y);
				        it != sweep.end(); sweep.erase(it++)) {
				int j = it->second;
				P d = ps[i] - ps[j];
				if (d.y > d.x) break;
				edges.push_back({d.y + d.x, i, j});
			}
			sweep[-ps[i].y] = i;
		}
		for (P& p : ps) if (k & 1) p.x = -p.x; else swap(p.x, p.y);
	}
	return edges;
}

void solve () {
    int n, m, k;
    cin >> n >> m >> k;
    char aux;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            
        }
}

int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}