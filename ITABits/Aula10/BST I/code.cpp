#include <bits/stdc++.h>

using namespace std;

struct node 
{
    char v;
    node* left;
    node* right;
};

string msg;
char a;
queue <char> pr;


void add (char a, node* &nd)
{
    if (nd == NULL)
    {
        nd = new node;
        nd->v = a;
        nd->left = nd->right = NULL;
        return;
    }

    if (a < nd->v)
        add (a,nd->left);
    else
        add (a, nd->right);
}

void pre (node* nd)
{
    if (nd == NULL)
        return;

    //cout << nd->v << ' ';
    pr.push(nd->v);
    pre(nd->left);
    pre(nd->right);
}

void in (node* nd)
{
    if (nd == NULL)
        return;
    
    in(nd->left);
    //cout << nd->v << ' ';
    pr.push(nd->v);
    in(nd->right);
}

void pos (node* nd)
{
    if (nd == NULL)
        return;
    
    pos(nd->left);
    pos(nd->right);
    //cout << nd->v;
    pr.push(nd->v);
}

bool search (char a, node* nd)
{
    if (nd == NULL)
        return false;
    if (a < nd->v)
        return search (a, nd->left);
    if (a > nd->v)
        return search (a,nd->right);   
    return true;
}

void print ()
{
    while (!pr.empty())
    {
        cout << " " << pr.front();
        pr.pop();
    }
}
int main ()
{
    node* tree = NULL;
    while (std :: cin >> msg)
    {
        if (msg == "I")
        {
            cin >> a;
            add(a, tree);
        }
        else if (msg == "PREFIXA")
        {
            //cout << tree->v;
            pre(tree);
            cout << pr.front();
            pr.pop();
            print();
            cout << '\n';
        }
        else if (msg == "INFIXA")
        {
            in(tree);
            cout << pr.front();
            pr.pop();
            print();
            cout << '\n';
        }
        else if (msg == "POSFIXA")
        {
            pos(tree);
            cout << pr.front();
            pr.pop();
            print();
            cout << '\n';
        }
        else
        {
            cin >> a;
            if (search(a, tree))
                cout << a << " existe\n";
            else
                cout << a << " nao existe\n";
        }
    }

    return 0;
}