#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
// #define int ll
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define endl '\n'
using namespace std;
const int NMAX= 1e6+10;
const ll M = 1e9+7;
void solve () {
    queue <string> ans, aux;
    int n;
    cin >> n;
    string str;
    str.pb('0');
    ans.push(str);
    str.clear();
    str.pb('1');
    ans.push(str);
    int sz = 2;
    stack<string> st;
    for (int i = 1; i < n; i++) {
        while(!aux.empty()) aux.pop();
        for (int i = 0 ; i < sz; i++) {
            st.push(ans.front());
            ans.push(ans.front());
            ans.pop();
        }
        for (int j = 0; j < sz; j++){
            str = ans.front();
            ans.pop();
            str.pb('0');
            aux.push(str);
        }

        for (int j = 0; j < sz; j++){
            str = st.top(); st.pop();
            str.pb('1');
            aux.push(str);
        }
        sz *= 2;
        ans = aux;
    }
    while (!ans.empty()) {
        cout << ans.front() << endl;
        ans.pop();
    }
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();
 
    return 0;
}