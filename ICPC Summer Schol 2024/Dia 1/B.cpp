#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200010;

vector <int> graph[NMAX], arestas[NMAX];

int marc[NMAX];
queue <int> bridges[NMAX];

int n, dia_max;

void dfs (int node, int block)
{
    marc[node] = 1;
    int dia = 1;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int viz = graph[node][i];
        int idArest = arestas[node][i];
        if (marc[viz] == 0)
        {
            if (dia == block)  dia++;
            bridges[dia].push(idArest);
            dfs( viz, dia );
            dia ++;
        }
    }
    if (dia > dia_max)
        dia_max = dia - 1;
}

int main ()
{
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        arestas[a].push_back(i);
        arestas[b].push_back(i);
    }

    dfs(1, -1);

    cout << dia_max << endl;

    for (int i = 1; i <= dia_max; i++)
    {
        cout << bridges[i].size();
        while(!bridges[i].empty())
        {
            cout << " " << bridges[i].front();
            bridges[i].pop();
        }
        cout << endl;
    }

    return 0;
}