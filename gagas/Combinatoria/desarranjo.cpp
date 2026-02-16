#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define ii pair<int,int>
#define f first
#define s second
#define endl '\n'
using namespace std;

int main() {
	fastio;
	int nt;
	cin >> nt;
	while (nt--) {
	    int n, a, b, mxf;
	    map<int,int> mp;
	    set<int> flt;
	    vi arr;
	    cin >> n;
	    for (int i = 0 ; i < n; i++) {
	        cin >> a;
	        mp[a]++;
	        arr.pb(a);
	        flt.insert(i);
	    }
	    mxf = mp.begin()->s;
	    for (auto p : mp)
	        mxf = max(mxf, p.s);
	    if (mxf > (n)/2) {
	        cout << "No" << endl;
	    }
	    else {
	        cout << "Yes" << endl;
	        
	        vi ans(n,0);
	        vii aux;
	        for (int i = 0 ; i < n; i++) {
	            aux.pb({arr[i],i});
	        }
	        
	        sort(aux.begin(), aux.end());
	        for (int i = 0; i < n; i++)
	            ans[aux[i].s] = aux[(i+mxf)%n].f;
	            
	        cout << ans[0];
	        for (int i = 1; i < n ; i++)
	            cout << ' ' << ans[i];
	        cout << endl;
	    }
	}
    return 0;
}
