#include <bits/stdc++.h>

using namespace std;

const int NMAX = 500010;
unordered_set<int> OddVertices;

vector <int> graph [NMAX], Arestas[NMAX];
pair<int,int> arestaId[NMAX];
int marc[NMAX], arestOut[NMAX];
int n, m, k;

bool dfs (int v, int pai)
{
    // cout << "Entrando no " << v << " do " << pai << endl;
    marc[v] = 1;
    int grau = -1;

    for (int i = 0; i < graph[v].size(); i ++)
    {
        int viz = graph[v][i];
        int idArest = Arestas[v][i];

        if (marc[viz] == 0)
        {
            if (dfs(viz, v) == 1)
            {
                arestOut[idArest] = 1;
                grau++;
            }
        }
    }

    // cout << "Vertice " << v << " com grau " << grau;
    if (OddVertices.find(v) != OddVertices.end()) // If vertice impar
    {
        // cout << " impar" << endl;
        if (grau % 2 == 0) // grau par
            return true;
        return false;
    }
    else
    {
        // cout << " par" << endl;
        if (grau % 2 == 1) // grau impar
            return true;
        return false;
    }
}





void add_arest (int a, int b)
{
    if (OddVertices.find(a) == OddVertices.end())
        OddVertices.insert(a);
    else
        OddVertices.erase(a);

    if (OddVertices.find(b) == OddVertices.end())
        OddVertices.insert(b);
    else
        OddVertices.erase(b);
}

int main ()
{
    cin >> n >> m >> k;
    int a,b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        add_arest(a,b);
    }

    if (OddVertices.size() == 0)
    {
        cout << "YES" << endl << 0 << endl;
        return 0;
    }

    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        Arestas[a].push_back(b);
        Arestas[b].push_back(a);
        arestaId[i] = {a,b};
    }

    if (dfs(*(OddVertices.begin()), -1) == true)
    {
        cout << "NO" << endl;
        return 0;
    }

    for (auto i : OddVertices)
        if (marc[i] == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    
    int r = 0;
    for (int i = 0; i < k; i++)
        if (arestOut[i] == 0)
            r++;

    cout << "YES" << endl << r << endl;

    pair <int, int> aux;
    for (int i = 0; i < k; i++)
        if (arestOut[i] == 0)
        {
            aux = arestaId[i];
            cout << aux.first << " " << aux.second << endl;
        }
    return 0;
}