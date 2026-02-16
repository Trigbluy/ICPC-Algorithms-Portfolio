#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(),cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < b; i++)
#define f first
#define s second
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int NMAX = 4e6;
struct node {
    int frq[26] = {};
    ii  pos[26] = {};
    node (){

    }
    node(int c, int p){
        frq[c]++;
        pos[c] = {p,p};
    }
};
node sg [NMAX];
void solve() {
    string str, ans;
    cin >> str;
    ans = str;
    n = str.size();
    seg st;
    st.init(n);
    st.build(str, 0, 0, n-1);
    int j = 0;
    for (int i = 0; i < n; i++){
        int ff = st.freq(j,n-1);
        // cout << i << ' ' << ff << endl;
        if(ff == str[i]-'a'+1) continue;
        if(ff < str[i] -'a' + 1){
            j = i+1;
            continue;
        }
        int ind = st.bb(ff, i, n-1) + 1;
        // cout << ind << endl;
        while(ind < n && str[ind] <= ff + 'a' - 1) ind++;
        for (int z = j; z < ind; z++) ans[z] = ff + 'a' - 1;
        i = ind - 1;
        j = i+1;
    }
    cout << ans << endl;
}
 /*
 abababzciu
 */
 
int main() {
    fastio;
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}