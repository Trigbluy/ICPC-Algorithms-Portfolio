#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n, c, s;

    cin >> n >> c >> s;
    int	pos = 0;
    int counter = (pos == (s-1));
    int aux;
    for (int i = 0 ; i < c; i++)
    {
        cin >> aux;
        pos += aux;
        if ((pos%n + n)%n == s-1)
            counter++;
    }
    cout << counter << endl;
    return 0;
}   