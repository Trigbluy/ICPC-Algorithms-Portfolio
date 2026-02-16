#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
// #define int ll
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
// #define endl '\n'
using namespace std;
const int NMAX= 1e6+10;
const ll M = 1e9+7;
int freq[27];
void solve () {
    string str;
    cin >> str;
    for (char c : str)
        freq[c - 'A']++;
    int ni = 0, li;
    for (int i = 0; i <= 'Z' - 'A'; i++)
        if (freq[i]%2){
            ni++;
            li = i;
        }
    
    if (ni > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    for (int i = 0 ; i <= 'Z' - 'A'; i++)
        for (int j = 0; j < freq[i]/2; j++)
            cout << (char)(i+'A');
    if(ni)
        cout << (char)(li + 'A');
    for (int i = 'Z' - 'A' ; i >= 0; i--)
        for (int j = 0; j < freq[i]/2; j++)
            cout << (char)(i+'A');
    cout << endl;
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();

    return 0;
}