#include <bits/stdc++.h> 
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define pb push_back
using namespace std;


void solve (){

    int n;
    vector <ll> wt;

    cin >> n;
    ll aux, sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> aux;
        wt.pb(aux);
        sum += aux;
    }

    ll md = sum/n;
    sum = 0;

    bool pos = true;

    for (int i = 0; i < n; i++){
        sum += wt[i];
        if (sum < (i+1)*md){
            pos = false;
            break;
        }
    }

    if (pos)
        cout << "YES" << endl;
    else
        cout << "NO"  << endl;
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