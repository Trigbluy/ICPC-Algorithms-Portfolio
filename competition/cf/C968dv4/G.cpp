#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back 
typedef long long ll;
#define endl '\n'
#define vi vector<int>
#define vll vector<ll>
using namespace std;
vll pai;
set<ll> el[8];
int dad (int c){
    while (pai[c] != pai[pai[c]])
        pai[c] = pai[pai[c]];
    return pai[c];
}
void unir (int a, int b) {
    if (dad(a) == dad(b))   return;
    for (auto c : el[a])
        el[b].insert(c);
    pai[a] = b;
}
void solve() {
    ll n, aux;
    vll arr;
    cin >> n;
    bool ok = false;
    for (int i = 0; i < n; i++){
        cin >> aux;
        arr.pb(aux);
        if((aux>>3) != (arr[0]>>3))
            ok = true;
    }
    if (ok) {
        sort(arr.begin(), arr.end());
        cout << arr[0];
        for (int i= 1;i <arr.size(); i++)
            cout << ' ' << arr[i];
        cout << endl;
    }
    else {
        ll qnt [8] = {0,0,0,0,0,0,0,0};
        for (int i = 0; i < n ; i++) {
            qnt[arr[i]%8]++;
        }
        ll cnc [8] = {0,0,0,0,0,0,0,0};
        for (int k = 0; k < 8; k++) {
            for (int j = 1; j < 4; j++) {
                if (qnt[(k&4) + (k+j)%4] != 0) {
                    int viz = (k&4) + (k+j)%4;
                    if (dad(viz) != dad(k)){
                        cnc [viz] = cnc[k] = 1;
                        unir(viz, k);
                    }
                }
                    
            }
        }
        vll tos[8];
        for (auto a: arr) {
            if (!(dad(a%8) == a%8 && !cnc[a&8])) {
                tos[dad(a&8)].pb(a);
            }
        }
        for (int k = 0; k < 8; k++)
            sort(tos[k].rbegin(), tos[k].rend());
        vll resp;
        for(auto a : arr) {
            if (dad(a%8) == a%8 && !cnc[a&8]) {
                resp.pb(a);
            }
            else {
                resp.pb(*tos[dad(a%8)].rbegin());
                tos[dad(a%8)].pop_back();
            }
        }
        cout << resp[0];
        for (int i= 1;i <resp.size(); i++)
            cout << ' ' << resp[i];
        cout << endl;
    }


}
int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}