#include <bits/stdc++.h>
using namespace std;
int main () {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = a; i <b; i+= c)
        cout << i << ' ';
    cout << b << endl;
    return 0;
}