#include <bits/stdc++.h>

using namespace std;

// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2261

vector <pair<int,set<int>>> comb;
set <int> analis;

int oi (int & cca)
{};

int main ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,a,b, nap;
    int t;

    cin >> n;
    while (n != 0)
    {
        b = 0;
        comb.clear();

        for (int k = 0; k < n; k++)
        {
            analis.clear();

            for (int i = 0; i < 5; i++)
            {
                cin >> a;
                analis.insert(a);
            }

            for (t = 0; t < b; t++)
                if (comb[t].second == analis)
                {
                    comb[t].first++;
                    t = b + 1;
                }

            if (t == b)
            {
                comb.push_back(make_pair(1,analis));
                b++;
            }
            
        }
        
        a = nap = comb[0].first;
        /*for (int i = 1; i < b; i++)
            if(nap == comb[i].first)
                a += nap;
            else if (nap < comb[i].first)
                a= nap = comb[i].first;*/
        
        for (auto & g : comb)
            if (nap == g.first)
                a+= nap;
            else if (nap < g.first)
                a = nap = g.first;

        cout << a << '\n';
        cin >> n;
    }

    return 0;
}