#include <bits/stdc++.h>
#define vi vector <int>
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
using namespace std;

void solve () {
    int n;
    string str;
    cin >> n >> str;
    map<char,char> dict;
    dict['\0'] = '\0';
    for (char i = 'a' ; i <= 'z' ; i++){
        dict[i] = i;
    }
    int q;
    cin >> q;
    while (q--) {
        char a, b;
        cin >> a >> b;
        for (auto v : dict) {
            if (v.ss == a)
                dict[v.ff] = b;
        }
    }

    for (auto c : str)
        cout << dict[c];
    cout << endl;
}
signed main () {
    int nt = 1;
    // cin >> nt;
    while(nt--)
        solve ();
    return 0;
}