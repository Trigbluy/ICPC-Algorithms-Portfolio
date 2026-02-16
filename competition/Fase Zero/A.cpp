#include <bits/stdc++.h>
using namespace std;
int main() {
 
    int a, ans = 6;
    for (int i = 0; i < 3; i++) {
    cin >> a;
    ans -= a;
    }
    cout << ans << endl;
    return 0;
}