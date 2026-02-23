#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fin(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
#define f first
#define s second
#define endl '\n'
#define int long long
const int NMAX = 1e5+3;
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve () {
    int n;
    string str;
    cin >> n >> str;
    int l = 1, r = n;
    fin(i,0,n){
        if (str[i] == 'a') {
            if (l%2)
                l++;
            else if (r%2)
                r--;
            else{
                cout << "NO" << endl;
                return;
            }
        }
        else if (str[i] == 'b') {
            if (!(l%2))
                l++;
            else if (!(r%2))
                r--;
            else{
                cout << "NO" << endl;
                return;
            }
        }
        else {
            if ((l%2) == (r%2))
                l++;
            else {
                if (str[i+1] == 'a'){
                    if (l%2)
                        r--;
                    else
                        l++;
                }
                else {
                    if (l%2)
                        l++;
                    else
                        r--;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int32_t main () {
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}