#include <bits/stdc++.h>

using namespace std;

map <int,int> colors;
int t, n, ne;
int main ()
{
    cin >> t;
    int b = 0;

    while (b++ < t)
    {
        colors.clear();
        cin >> n;
        ne = 0;
        int a, last = 0;
        bool pos = true;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (colors.find(a) == colors.end())
            {
                colors.emplace(a,ne++);
                last = a;
            }
            else if (a != last)
                pos = false;
        }

        cout << "Case #" << b << ':';
        if (pos)
        {
            vector <int> help;
            help.resize(ne+1);

            for (auto x : colors)
                help[x.second] = x.first;
            for (int i = 0; i < ne; i++)
                cout << " " << help[i];
            cout << '\n';
        }
        else
            cout << " IMPOSSIBLE\n";
    
    }
    return 0;
}