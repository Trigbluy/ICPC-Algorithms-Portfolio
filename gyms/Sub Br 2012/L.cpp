#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
typedef long long ll;
#define maxn 10006
using namespace std;

int main () {
    fastio;
    ll n;
    vll sk;
    while (cin >> n) {
        ll aux = n;
        sk.clear();
        sk.pb(1);
        for (ll i = 2; aux > i; i++) {
            // cout << i ;
            if (i*i > aux) {
                i = aux;
                sk.pb(*sk.rbegin()*i);
                for (int j = sk.size() - 2; j > 0; j--){
                    sk[j] = i * sk[j-1] + sk[j];
                }
                break;
            }
            else if (aux%i == 0) {
                // cout << "prime: " <<i << endl;
                while (aux%i == 0) aux/=i;
                // cout << "Ok" << endl;
                sk.pb((sk[sk.size()  -1])*i);
                for (int j = sk.size() - 2; j > 0; j--){
                    sk[j] = i * sk[j-1] + sk[j];
                }
                // cout << "Ok" << endl;
                
        // cout << "/////////////" << endl;
        // for (int i = 0; i < sk.size(); i++) {
        //     cout << ' ' << sk [i];
        // }   cout << endl;

            }
        }
        // cout << "/////////////" << endl;
        // for (int i = 0; i < sk.size(); i++) {
        //     cout << ' ' << sk [i];
        // }
        ll ans = 0;
        for (int i = 0; i < sk.size(); i++) {
            ans += sk[sk.size() - 1 - i] * (1 - 2 * (i%2));
        }
        // cout << " " << ans << endl;
        ans *= (n/(*sk.rbegin()));
        cout << ans/2 << endl;
    }
    return 0;
}