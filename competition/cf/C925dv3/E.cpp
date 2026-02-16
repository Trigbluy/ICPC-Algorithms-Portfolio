#include <bits/stdc++.h> 
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define ull unsigned ll
#define pb push_back
#define ff first
#define ss second
#define pii pair <ll,ll>
#define vii vector <pii>
#define endl '\n'

using namespace std;

const int NMAX = 1e5 + 10;
vii arr;

pii valuete (ll a) {
    int aux = a;
    int c1 = 0, c2 = 0;

    while (aux != 0 && aux % 10 == 0) {
        c1++, c2++;
        aux /= 10;
    }
    while (aux != 0) {
        aux /= 10;
        c2++;
    }

    return {c1,c2};
}

void solve (){

    int n, m;
    cin >> n >> m;
    arr.clear();

    int aux;
    for (int i = 0; i < n ; i++){
        cin >> aux;
        arr.pb(valuete(aux));
        // cout << aux << " -> (" << valuete(aux).ff << " , " << valuete(aux).ss << ")" << endl;
    }

    sort (arr.rbegin(), arr.rend());
    // for (auto p : arr) {
    //     cout << "(" << p.ff << " , " << p.ss << ")" << endl;
    // }

    ll max = 0;
    for (int i = 0; i < arr.size(); i++) {
        pii p = arr[i];
        ll nz = p.ff;
        ll na = p.ss;

        if (i % 2 == 0)
            max += na - nz;
        else
            max += na;
    }

    // cout << max << endl;
    if (max > m)
        cout << "Sasha" << endl;
    else
        cout << "Anna"  << endl;
}

int main (){
    fastio;
    int nt;
    cin >> nt;
    while (nt--){
        solve();
    }
    return 0;
}