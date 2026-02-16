#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n,m,d;
    cin >> n >> m >> d;
    char color [] = {'R','Y','G','B'};

    if (d % 2 == 1)
    {
        for (int i = 0 ; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int ind = (i+j) % 2;
                cout << color [ind];
            }
            cout << endl;
        }
        return 0;
    }

    int offset =  (m/(d) + 2)*(d)*2;
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int indP = ((i+j)/(d)) % 2;
            int indS = ((((i - j + offset)/(d)) % 2) + 2) % 2;
            int indFinal = indP*2 + indS;
            cout << color[indFinal];
        }

        cout << endl;
    }

    return 0;
}