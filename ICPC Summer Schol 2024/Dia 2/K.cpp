#include <bits/stdc++.h>

using namespace std;

const int NMAX = 50010;

vector <int> graph[NMAX][2];

int marc[NMAX], pilha[NMAX], comp[NMAX], entra[NMAX], sai[NMAX];

pair <int, int> arestas[NMAX];

int n, m, c, p, t;

void dfs (int v, int pai, int ind)
{
    marc[v] = !ind;
    comp[v] = c;
    for (int i = 0; i < graph[v][ind].size(); i++)
    {
        int viz = graph[v][ind][i];
        if (marc[viz] == ind)
            dfs (viz, v, ind);
    }
    if (ind == 0)
        pilha[++p] = v;
}

void reset ()
{
//     memset(marc, 0, sizeof(marc));
//     memset(pilha, 0, sizeof(pilha));
//     memset(comp, 0, sizeof(comp));
//     memset(arestas, 0, sizeof(arestas));
//     memset(graph, 0, sizeof(graph));
//     memset(entra, 0, sizeof(entra));
//     memset(sai, 0, sizeof(sai));

    c = 0;
    p = -1;

    for (int i = 0; i < NMAX; i++)
    {
        graph[i][0].clear();
        graph[i][1].clear();
        entra[i] = sai[i] = marc[i] = 0;
    }
}

int main ()
{
    cin >> t;
    for (int n_c = 1; n_c <= t; n_c++)
    {
        cin >> n >> m;

        reset();

        int a,b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            graph[a][0].push_back(b);
            graph[b][1].push_back(a);
            arestas[i] = {a,b};
        }

        for (int i = 1; i <= n; i++)
            if (marc[i] == 0)
                dfs(i, -1, 0);

        for (int i = n-1; i >= 0; i--)
        {
            int aux = pilha[i];
            if (marc[aux] == 1)
            {
                c++;
                dfs(aux, -1, 1);
            }
        }

        if (c <= 1)
        {
            cout << "0" << endl;
            continue;
        }

    	for (int i = 0; i < m; i++)
        {
            a = arestas[i].first;
            b = arestas[i].second;

            int comp_sai   = comp[a];
            int comp_entra = comp[b];

            sai   [comp_sai] = 1;
            entra [comp_entra] = 1;
        }

        int num_nsai = 0;
        int num_nentra = 0;

        for (int i = 1; i <= c; i++)
        {
            if (sai[i] == 0)
                num_nsai++;
            if (entra[i] == 0)
                num_nentra++;
        }

        cout << max (num_nsai, num_nentra) << endl;
    }

    return 0;
}