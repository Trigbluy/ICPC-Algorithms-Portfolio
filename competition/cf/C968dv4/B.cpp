#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define vi vector<int>
using namespace std;
void solve() {
    string str;
    cin >> str;
    char a = str[0];
    bool cant = true;
    int c = 1;
    for (int i = 1; i < str.size(); i ++)
        if (str[i] != a) {
            c= i;
            cant = false;
        }
    if (cant)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        swap(str[0], str[c]);
        cout << str << endl;
    }

}
int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}