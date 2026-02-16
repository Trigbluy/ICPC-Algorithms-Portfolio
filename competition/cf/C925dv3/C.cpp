#include <bits/stdc++.h> 
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define pb push_back
#define endl '\n'

using namespace std;

const int NMAX = 1e5 + 10;

void solve (){

    int n;
    cin >> n;
    vector <int> arr;

    int aux;
    for (int i =0; i < n ; i++){
        cin >> aux;
        arr.pb(aux);
    }

    int m = 0, p = n-1;
    int am = arr[0], ap = arr[n-1];

    while (m < n-1 && am == arr[m+1]) m++;

    while (m < p && ap == arr[p-1]) p--;

    if (am == ap)
        if (m == n - 1)
            cout << 0 << endl;
        else
            cout << p - m - 1 << endl;
    else
        cout << min (n - m - 1, p) << endl;
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