#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define vi vector<int>
typedef long long ll;
#define maxn 10006
using namespace std;

int main () {
    fastio;
    int n, l, c;
    while (cin >> n) {
        cin >> l >> c;
        string str;
        vi arr;
        for (int i = 0; i < n; i++) {
            cin >> str;
            arr.pb(str.size());
        }
        int nc = arr[0], nl = 1;
        for (int i = 1; i < n; i++) {
            nc += arr[i] + 1;
            if (nc > c) {
                nc = arr[i];
                nl++;
            }
        }
        if (nc == 0) nl--;
        // cout << "\\\\ " << nl << ' ' << nc << endl;
        cout << (nl + (l - 1))/l << endl;
    }
    return 0;
}