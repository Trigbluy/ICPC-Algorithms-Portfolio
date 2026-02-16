#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200010;

vector <int> graph [NMAX], reverso[NMAX];

int marc[NMAX], pilha [NMAX];

int n, m, p, c;

void dfs (int node)
{
    marc[node] = 1;
    for(int i = 0; i < graph[node].size(); i++)
    {
        int viz = graph[node][i];
        if (marc[viz] == 0)
        {
            dfs(viz);
        }
    }

    pilha[++p] = node;
}

void dfs2 (int node)
{
    marc[node] = 2;
    for(int i = 0; i < reverso[node].size(); i++)
    {
        int viz = reverso[node][i];
        if (marc[viz] == 1)
        {
            dfs2(viz);
        }
    }
}

int main ()
{
    cin >> n >> m;

    int a,b;
    for (int i = 0; i < m;  i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        reverso[b].push_back(a);
    }

    p = -1;
    for (int i = 1; i <= n; i++)
        if (marc[i] == 0)
            dfs(i);
    
    for (int i = p; i >= 0; i--)
        if (marc[pilha[i]] == 1)
        {
            c++;
            if (c == 2)
                {cout << "NO" << endl << pilha[i] << " " << pilha[p] << endl; return 0;}
            dfs2(pilha[i]);
        }

    cout << "YES" << endl;

    return 0;
}