#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string mp;
        cin >> mp;
        int i = 0;
        while (i < n && mp[i] == 'W') i++;

        // i = primeiro preto
        int j = n-1;
        while (j >= 0 & mp[j] == 'W') j--;
        // j = ultimo preto

        // i -> j
        cout << j - i + 1 << endl;
    }
    return 0;
}