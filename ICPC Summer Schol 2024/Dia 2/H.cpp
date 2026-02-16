#include <bits/stdc++.h>

using namespace std;

const int NMAX = 50010;

vector <int> graph[NMAX], arestas[NMAX],  bcTree[NMAX];
int marc[NMAX], marcArest[NMAX], low[NMAX], pre[NMAX], pilha[NMAX],
    
    comp[NMAX], artPoints[NMAX], marcComp[NMAX], ponte[NMAX];

unordered_set <int> compPoints[NMAX];

int n, t, p, c;

void novaCompBi (int idArest)
{
    c++;
    int aux;
    do
    {
        aux = pilha[p--];
        comp[aux] = c;
        if(p == -1) break;
    } while (aux != idArest);
    
}

void dfs (int v, int pai)
{
    marc[v] = 1;
    low[v] = pre[v] = ++t;
    int quantFilhos = 0;
    bool artPoint = false;
    
    for(int i = 0 ; i < graph[v].size(); i ++)
    {
        int viz = graph[v][i];
        int idArest = arestas[v][i];

        if (marcArest[idArest] == 1) continue;
        marcArest[idArest] = 1;
        pilha[++p] = idArest;

        if (marc[viz] == 0)
        {
            quantFilhos++;
            dfs(viz, v);
            low[v] = min(low[v], low[viz]);

            if (v == 1 && quantFilhos >= 2) artPoint = true;
            if (v != 1 && low[viz] >= pre[v]) artPoint = true;

            if (artPoint)
            {
                artPoints[v] = 1;
                novaCompBi(idArest);
            }
        }
        else
        {
            low[v] = min (low[v], pre[viz]);
        }
        if (low[v] >= pre[v])
            ponte[idArest] = 1;
    }
}

void dfs2 (int v)
{
    marc[v] = 2;
    for (int i = 0; i < graph[v].size(); i ++)
    {
        int viz = graph[v][i];
        int idArest = arestas[v][i];
        int comp_aresta = comp[idArest];

        if (marcArest[idArest] == 2) continue;
        marcArest[idArest] = 2;

        if (marc[viz] == 1)
        {
            dfs2(viz);
        }

        compPoints[comp_aresta].insert(v);
        compPoints[comp_aresta].insert(viz);
    }
}

int main ()
{
    int n_cases = 0;
    cin >> n;
    while(n)
    {

        // =====================================

        // ESTA AREA ESTA CAUSANDO RUNTIME ERROR
        
        n_cases++;

        for (int i = 0; i < NMAX; i++)
        {
            compPoints[i].clear();
            graph[i].clear();
            arestas[i].clear();
            bcTree[i].clear();
            
            marc[i] = 0;
            marcArest[i] = 0;
            marcComp[i] = 0;
            low[i] = 0;
            pre[i] = 0;
            comp[i] = 0;
            ponte[i] = 0;
            artPoints[i] = 0;
        }

        // ========================================

        int a, b;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            arestas[a].push_back(i);
            arestas[b].push_back(i);
        }

        t = 0; p = -1; c = 0;
        dfs(1, -1);
        novaCompBi(-1);

        for (int i = 1; i <= n; i++)
        {
            if (artPoints[i] != 1) continue;
            
            c++;
            artPoints[i] = c;
            for (int j = 0; j < arestas[i].size(); j++)
            {
                int idArest = arestas[i][j];
                int comp_aresta = comp[idArest];
                if (marcComp[comp_aresta] == 0)
                {
                    marcComp[comp_aresta] = 1;
                    bcTree[comp_aresta].push_back(c);
                    bcTree[c].push_back(comp_aresta);
                }
            }

            for (int j = 0; j < arestas[i].size(); j++)
            {
                int idArest = arestas[i][j];
                int comp_aresta = comp[idArest];
                marcComp[comp_aresta] = 0;
            }
        }
        

        dfs2 (1);

        unsigned long long ans = 1;
        int num_leafs = 0;
        for (int i = 1; i < c + 1; i++)
        {
            if (bcTree[i].size() == 1)
            {
                num_leafs++;
                ans *= compPoints[i].size() - 1;
            }
        }

        cout << "Case " << n_cases << ": " << num_leafs << " " << ans << endl;
        cin >> n;
    }
    return 0;
}