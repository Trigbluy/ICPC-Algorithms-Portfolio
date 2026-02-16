#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void solve () {
    string str, aux;
    cin >> str;
    for (auto c : str)
        switch (c) {
            case 'a':
                aux.pb (c);
                break;
            case 'e':
                aux.pb (c);
                break;
            case 'i':
                aux.pb (c);
                break;
            case 'o':
                aux.pb (c);
                break;
            case 'u':
                aux.pb (c);
                break;
        }
    
    bool okay = true;
    int n = aux.size();
    for (int i = 0; i < n; i++) {
        if (aux[i] != aux[n-1 - i])
            okay = false;
    }
    if (okay)
        cout << 'S' << endl;
    else
        cout << 'N' << endl;
}

int main () {
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}