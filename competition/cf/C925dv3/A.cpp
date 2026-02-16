#include <bits/stdc++.h> 
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


void solve (){
    int n;
    cin >> n;

    if (n == 3*26){
        cout << "zzz" << endl;
    } else if ( n > 2*26) {
        char aux = 'a' + n % 26 - 1;
        cout << aux << "zz" << endl;
    } else if (n > 27) {
        char aux = 'a' + (n - 1 )% 26 - 1;
        cout << "a" << aux << 'z' << endl;
    } else {
        char aux = 'a' + (n-2)%26 -1;
        cout << "aa" << aux << endl;
    }
}

int main (){
    int nt;
    cin >> nt;
    while (nt--){
        solve();
    }
    return 0;
}