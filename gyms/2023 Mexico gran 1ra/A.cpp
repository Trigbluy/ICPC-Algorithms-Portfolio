#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main () {
    fastio;
    int n, a;
    cin >> n;

    string aux, NAME;
    map<string, int> conj;
    while (n--) {
        cin >> a;
        NAME.clear();
        while (a--) {
            cin >> aux;
            NAME.push_back(aux[0]);
        }
        conj[NAME]++;
    }

    int resp = 0;
    for (auto p : conj)
        if (p.second == 1)
            resp++;
    cout << resp << endl;
    return 0;
}