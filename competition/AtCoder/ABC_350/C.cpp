#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pb push_back
#define vi vector<int>
using namespace std;
const int NMAX = 2e5+100;
int arr[NMAX], pos[NMAX];
queue<int> tp;
int main () {
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int nt = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] != i) {
            // troco pos[arr[i]] com pos[i]
            int j = pos[arr[i]], k = pos[i];
            nt++;
            if(j>k) swap(j,k);
            tp.push(j); tp.push(k);
            swap(pos[arr[i]], pos[i]);
            swap(arr[j], arr[k]);
        }
    }
    cout << nt << endl;
    while(nt--) {
        cout << tp.front() << ' '; tp.pop();
        cout << tp.front() << endl; tp.pop();
    }
    return 0;
}