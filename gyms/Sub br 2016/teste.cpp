#include <bits/stdc++.h>
using namespace std;
int main () {
    vector <int> v;
    for (int i = 3; i < 10; i++)
        v.push_back(i);
    int a;
    cin >> a;

    cout << lower_bound(v.begin(), v.end(), a) - v.begin() << endl;
    cout << *lower_bound(v.begin(), v.end(), a) << endl;
}