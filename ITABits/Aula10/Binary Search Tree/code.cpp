 #include <bits/stdc++.h>
// https://www.beecrowd.com.br/judge/en/runs/code/29826220
using namespace std;
struct node
{
    int v;
    node* first;
    node* second;
};

int n,m;

void add (int a, node* &nd)
{
    if (nd == NULL)
    {
        nd = new node;
        nd->first = nd->second = NULL;
        nd->v = a;
        return;
    }
    
    if (a < nd->v)
        add (a, nd->first);
    else
        add (a, nd->second);
}

void del (node* nd)
{
    if (nd == NULL)
        return;
    
    del(nd->first);
    del(nd->second);
    delete nd;
}

void ppre (node* nd)
{
    if (nd == NULL)
        return;

    cout << ' ' << nd->v;
    ppre(nd->first);
    ppre(nd->second);
}

void pin (node* nd)
{
    if (nd == NULL)
        return;

    pin(nd->first);
    cout << ' ' << nd->v;
    pin(nd->second);
}

void ppost (node* nd)
{
    if (nd == NULL)
        return;

    ppost(nd->first);
    ppost(nd->second);
    cout << ' ' << nd->v;
}

int main ()
{
    cin >> n;
    node* tree = NULL;
    for (int j = 0; j < n; j ++)
    {
        int a;
        del (tree);
        tree = NULL;
        cin >> m;
        for (int i = 0; i < m; i ++)
        {
            cin >> a;
            add (a, tree);
            //cout << "a";
        }

        cout << "Case " << j + 1 << ":\nPre.:";
        ppre(tree);
        cout << "\nIn..:";
        pin(tree);
        cout << "\nPost:";
        ppost(tree);
        cout << "\n\n";

    }
    return 0;
}