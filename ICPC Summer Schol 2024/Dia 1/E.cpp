#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200010;

vector <int> graph[NMAX];

int marc [NMAX], uni[NMAX];

int n, k;
unsigned long long dist;

int dfs (int v)
{
    marc[v] = 1;
    
    int nUni = uni[v];
    for (int i = 0; i < graph[v].size(); i ++)
    {
        int viz = graph[v][i];
        if (marc[viz] == 0)
        {
            int aux = dfs (viz);
            nUni += aux;
            dist += min (aux, 2*k - aux);
        }
    }

    return nUni;
}

int main ()
{
    cin >> n >> k;
    int a,b;
    for (int i = 0; i < 2*k; i++)
    {
        cin >> a;
        uni[a] = 1;
    }

    for (int i = 0; i < n - 1; i ++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    cout << dist << endl;

    return 0;
}