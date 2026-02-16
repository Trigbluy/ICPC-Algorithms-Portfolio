#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < (int)b; i++)
using namespace std;
void solve (){
    int n, a;
    cin >> n;
    set<int> st;
    fin(i,0,n){
        cin >> a;
        st.insert(a);
    }
    cout << st.size() << endl;
}
int32_t main (){
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}