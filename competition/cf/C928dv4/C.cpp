#include <bits/stdc++.h>
#define ll long long
using namespace std;
map <int, ll> mp;
ll sdg (int n) {
    int s = 0;
    while (n) {
        s += n%10;
        n /= 10;
    }
    return s;
}

int main () {
    int n = 1;
    int sum = 0;

    while (n <= 200000) {
        sum += sdg(n);
        mp[n] = sum;
        n++;
    }

    int nt;
    cin >> nt;
    while (nt--) {
        cin >> n;
        cout << mp[n] << endl;
    }
    return 0;
}