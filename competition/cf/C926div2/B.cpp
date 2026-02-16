#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve () {
    int n, k;
    cin >> n >> k;
    int ext = n - 2;
    
    if(k <= 2*(n + ext)){
        cout << (k+1)/2 << endl;
    }
    else {
        cout << k - 2*(n + ext) + (n + ext) << endl;
    }
}

int main (){
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}