#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int a, b;
    cin >> a >> b;
    int num = max(a,b);
    string aux;
    for (int i = 0; i < 26; i++)
        for (int p = 0; p < 26; p++)
            for (int q = 0; q < 26; q++)
                for (int r = 0; r < 26; r++)
                {
                    num--;
                    cout << (char) ('a' + i) << (char) ('a' + p) << (char) ('a' + q) << (char) ('a' + r) << " ";
                    if (num == 0)
                    {
                        cout << endl;
                        return 0;
                    }
                }
}