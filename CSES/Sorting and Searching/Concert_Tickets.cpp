#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
void solve (){
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> st;
    int a,b;
    fin(i,0,n){
        cin >> a;
        st.insert(a);
    }
    fin(j,0,m){
        cin >> b;
        auto it = st.lower_bound(b);
        if(it == st.end())
            cout << -1 << endl;
        else{
            cout << *it << endl;
            st.erase(it);
        }
    }
}
int32_t main (){
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}