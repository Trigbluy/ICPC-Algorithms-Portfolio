#include <bits/stdc++.h>

using namespace std;

vector<int> lights;
int t, r, m, n;

int search(int want)
{
    int a, b;
    a = 0;
    b = n - 1;
    while (a < b)
    {
        if (lights[(a + b) / 2] >= want)
            b = (a + b) / 2;
        else
            a = (a + b) / 2 + 1;
    }

    if (lights[a] <= want)
        return a;
    else
        return a - 1;
}

int main()
{
    cin >> t;
    int b = 0;

    while (b++ < t)
    {
        lights.clear();
        cin >> m >> r >> n;
        lights.resize(n + 1);

        int a;
        int lastl = 0, lastp = -1;
        int np = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a;
            lights[i] = a;
        }

        bool pos = true;

        while (lastl < m)
        {
            int aux = search(lastl + r);
            
            if (-r <= lastl - lights[aux] && lastl - lights[aux] <= r)
            {
                if (aux != lastp)
                {
                    lastp = aux;
                    lastl = lights[lastp] + r;
                    np++;
                }
                else
                {
                    lastl = m + 1;
                    pos = false;
                }
            }
            else
            {
                lastl = m + 1;
                pos = false;
            }
        }

        if (pos)
            cout << "Case #" << b << ": " << np << '\n';
        else
            cout << "Case #" << b << ": IMPOSSIBLE\n";
    }

    return 0;
}