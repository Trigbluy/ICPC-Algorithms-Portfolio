#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2e5 + 100;
int qnt[NMAX];
int main (){
    int n, aux;
    cin >> n;
    for (int i = 0; i < 3*n; i++){
        cin >> aux;
        int ind = aux + 1e5 + 10;
        qnt[ind]++;
    }
    for (int i = 0; i < NMAX; i++) {
        if (qnt[i]%3) {
            cout << "Y" << endl;
            return 0;
        }
    }
    cout << "N" << endl;
    return 0;
}