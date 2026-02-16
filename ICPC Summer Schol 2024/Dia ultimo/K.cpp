#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int val [3];
    for (int i = 0; i < 3; i++)
        cin >> val[i];
    
    sort(val, val +3);
    bool pos = false;
    if (val[0] == val[1])             pos = true;
    if (val[1] == val[2])               pos = true;
    if (val[0] + val[1] == val[2])       pos = true;

    if (pos)
        cout << 'S' << endl;
    else
        cout << 'N' << endl;
    return 0;
}   