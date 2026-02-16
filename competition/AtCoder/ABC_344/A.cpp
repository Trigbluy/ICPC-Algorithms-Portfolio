#include <bits/stdc++.h>
#define pb push_back
using namespace std;


void solve () {
    stack<int> resp;
    int aux = -1;
    while (aux != 0) {
        cin >> aux;
        resp.push(aux);
    }
    while (!resp.empty()) {
        cout << resp.top() << endl;
        resp.pop();
    }
}
int main () {
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}