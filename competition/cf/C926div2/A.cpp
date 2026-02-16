#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    int max, min, aux;
    cin >> max;
    min = max;
    for (int i = 1; i < n; i++){
        cin >> aux;
        if (aux < min)
            min = aux;
        if (aux > max)
            max = aux;
    }

    cout << max-min << endl;
}
int main (){
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}