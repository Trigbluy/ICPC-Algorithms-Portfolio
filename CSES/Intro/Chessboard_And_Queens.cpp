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
typedef vector<ll> vll;
const int NMAX= 1e6+10;
const ll M = 1e9+7;
int m[8][8];
void solve () {
    char c;
    for (int i = 0 ; i < 8; i++)
        for (int j = 0 ; j < 8; j++){
            cin >> c;
            m[i][j] = (c == '*');
        }
    int p [8] = {0,1,2,3,4,5,6,7};
    ll ans = 0;
    do{
        bool aux1[15] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0};
        bool aux2[15] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0};
        bool ok = true;
        for (int i = 0; i < 8; i++){
            if (aux1[i+p[i]] || aux2[i-p[i]+7] || m[i][p[i]]){
                ok = false;
                break;
            }
            aux1[i+p[i]] = aux2[i-p[i]+7] = true;
        }
        if (ok)
            ans ++;
    } while (next_permutation(p,p+8));
    cout << ans << endl;
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();
 
    return 0;
}