#include <bits/stdc++.h>

using namespace std;

int n;
bool vec[1003];
int main ()
{
    cin >> n;
    for (int i = 0; i< n; i++)
    {
        int a;
        cin >> a;
        vec[a] = true;
    }

    for (int i = 1; i < 1001; i++)
    {
        if (vec[i])
        {
            cout << i;
            n--;
            if (vec[i+1] && vec[i+2])
            {
                int q = i;
                while (vec[q])
                    q++;
                q--;
                cout << -q;
                n-= q-i;
                i = q;
            }

            if (n)
                cout << ' ';
        }
    }
    cout << endl;
    return 0;
}