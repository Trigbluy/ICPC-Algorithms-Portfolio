#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
void solve (){
    int n, x,a;
    cin >> n >> x;
    multiset<int,greater<int>> st;
    fin(i,0,n){
        cin >> a;
        st.insert(a);
    }
    int ans = 0;
    while(!st.empty()){
        ans++;
        auto it = st.begin();
        a = *it;
        st.erase(it);
        it = st.lower_bound(x-a);
        if(it!=st.end())
            st.erase(it);
    }
    cout << ans << endl;
}
int32_t main (){
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}