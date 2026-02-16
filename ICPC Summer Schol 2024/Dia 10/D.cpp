#include <bits/stdc++.h>
using namespace std;

vector <int> in, out;
int val(vector <int>& V, int ind)
{
    if (ind >= V.size() || ind < 0) return 0;
    return V[ind];
}
bool poss_fold (vector <int> from)
{
    int n = from.size();
    int m = out.size();
    vector<int> mod;
    for (int i = 0; i < n - 1; i++) // Fold i ->- (0, 1 , 2 , 3 , 4) (i=3)
    {
        mod.clear();
        int nsz = max (i + 1, n - 1 - i);
        int pivot = i + 1;
        if (nsz < m) continue;

        for (int j = 0; j < nsz; j++)
        {
            int d = nsz - 1 - j;
            mod.push_back(val(from, pivot - 1 - d) + val (from, pivot + d));
        }

        if (mod.size() == out.size())
        {
            bool poss1 = true;
            for (int o = 0; o < out.size(); o++)
                if (mod[o] != out[o])
                    poss1 = false;
            bool poss2 = true;
            for (int o = 0; o < out.size(); o++)
                if (mod[o] != out[out.size() - 1 - o])
                    poss2 = false;
            if (poss1 || poss2) return true;
        }

        if (poss_fold(mod) == true)
            return true;
    }
    return false;
}

int n,m;
int main ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n)
    {
        int aux;
        in.clear();
        out.clear();
        int s1 = 0, s2 = 0;
        for(int i = 0 ; i < n ; i ++)
        {
            cin >> aux; s1 += aux;
            in.push_back(aux);
        }

        cin >> m;
        for(int i = 0 ; i < m ; i ++)
        {
            cin >> aux; s2 += aux;
            out.push_back(aux);
        }
        
        if (s1 != s2)
        {
            cout <<"N\n";
            continue;
        }

        bool poss = true;
        if (in.size() == out.size())
        {
            for (int o = 0; o < out.size(); o++)
                if (in[o] != out[o])
                {
                    poss = false;
                    break;
                }
            bool baum = true;
            for (int o = 0; o < out.size(); o++)
                if (in[o] != out[n - 1 - o])
                {
                    baum = false;
                    break;
                }
            if (poss || baum)
            {
                cout << "S\n";
                continue;
            }
            else
            {
                cout << "N\n";
                continue;
            }
        }
        if (poss_fold(in))
        {
            cout << "S\n";
            continue;
        }
        else
        {
            cout << "N\n";
            continue;
        }
    }
    return 0;
}