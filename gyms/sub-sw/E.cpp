#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main (){
    ios_base :: sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    int n, na = 0, ans = 0;
    char aux;
    cin >> n;
    while (n--){
        cin >> aux;
        if (aux == '(') na++;
        else if (aux == ')' && na > 0) {
            ans += 2;
            na--;
        }
    }
    cout << ans << endl;
    return 0;
}