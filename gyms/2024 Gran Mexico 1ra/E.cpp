#include <bits/stdc++.h>
using namespace std;
int main () {
    int a, b ,k;
    cin >> a >> b >> k;
    cout << a+b;
    for (int i = 2; i <= k; i++)
        cout << ' ' << a*i+b;
    cout << endl;
    return 0;
}