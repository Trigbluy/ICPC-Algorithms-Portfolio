#include <bits/stdc++.h>

using namespace std;

// https://www.beecrowd.com.br/judge/en/problems/view/1028

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, n1, n2, rest;

    cin >> n;

    for (int i = 0; i < n; i ++)
    {
        cin >> n1 >> n2;
        do
        {
            rest = n1%n2;
            n1 = n2;
            n2 = rest;
        } while (rest != 0);
        
        cout << n1 << '\n';
    }
    return 0;
}