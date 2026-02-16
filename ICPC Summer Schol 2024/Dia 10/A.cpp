#include <bits/stdc++.h>

using namespace std; 
int a,b,c;
int main(){
    while (cin >> a >> b >> c)
    {
        if (a == b && c!=a)
            cout << "C\n";
        else if (a == c && b != a)
            cout << "B\n";
        else if (b == c && a != b)
            cout << "A\n";
        else
            cout << "*\n";
    }
    return 0;
}