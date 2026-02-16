#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200010;

vector<int> graph[NMAX];
int marc[NMAX], connected[NMAX];

int n, n_arestas;

void connect (int node)
{
    if (node == -1) return;

    connected[node] = 1;
    for (int i = 0; i < graph[node].size(); i++)
        connected[graph[node][i]] = 1;
    n_arestas++;
}

void dfs (int node, int pai)
{
    marc[node] = 1;
    for (int i = 0; i < graph[node].size(); i ++)
    {
        int viz = graph[node][i];
        if (marc[viz] == 0)
        {
            dfs(viz, node);
        }
    }

    if (connected[node] == 0)
        connect(pai);
}

int main ()
{
    cin >> n;

    int a, b;
    for (int i = 0; i < n - 1; i ++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < graph[1].size(); i++)
    {
        connect(graph[1][i]);
        n_arestas--;
    }
    dfs(1,-1);

    cout << n_arestas << endl;

    return 0;
}