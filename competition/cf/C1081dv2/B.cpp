#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fin(a,b,c) for(int a = b; a < c; a++)
#define pb push_back
#define f first
#define s second
// #define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve () {
    int n, ans = 0;
    char att, last;
    cin >> n;
    vi mvs;
    vector<char> arr(n);
    fin (i,0,n)
        cin >> arr[i];
    last = '1';
    fin(i,0,n){
        att = arr[i];
        // cout << i << " - " << arr[i] << " - " << ans << endl;
        if (last != '0' + (att + ans)%2){
            last = '0' + (att + ans)%2;
            ans++;
            mvs.pb(i+1);
        }
    }

    int n_trades_last = ans-(!mvs.empty() && (*mvs.rbegin() == n));
    if ((att == '0' && !(n_trades_last%2))
    ||  (att == '1' &&  n_trades_last%2)) {
        cout << ans << endl;
        if (!mvs.empty()) {
            cout << mvs[0];
            fin(i,1,ans)
                cout << ' ' << mvs[i];
            cout << endl;
        }
    }
    else {

        last = '0';
        ans = 0;
        mvs.clear();
        fin(i,0,n){
            att = arr[i];
            // cout << i << " - " << arr[i] << " - " << ans << endl;
            if (last != '0' + (att + ans)%2){
                last = '0' + (att + ans)%2;
                ans++;
                mvs.pb(i+1);
            }
        }
        // cout << ans << endl;
        
        n_trades_last = ans-(!mvs.empty() && (*mvs.rbegin() == n));
        // cout << n_trades_last << endl; // 2
        // cout << att << endl;
        if ((att == '0' && !(n_trades_last%2))
        ||  (att == '1' &&  n_trades_last%2)) {
            cout << ans << endl;
            if (!mvs.empty()) {
                cout << mvs[0];
                fin(i,1,ans)
                    cout << ' ' << mvs[i];
                cout << endl;
            }
        }
        else
            cout << -1 << endl;
    }

    // cout << "#########" << endl;
    // for(int i : mvs)
    //     cout << i << ' ';
    // cout << endl;
}

int main () {
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}