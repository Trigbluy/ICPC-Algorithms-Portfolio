#include <bits/stdc++.h>
using namespace std;
int main () {
    int q;
    cin >> q;
    vector <int> seq;
    int qr, aux;
    queue <int> to_p;
    while (q--) {
        cin >> qr >> aux;
        if (qr == 1) {
            seq.push_back(aux);
        }
        else {
            cout << seq[seq.size() - aux] << endl;
        }
    }
    return 0;
}