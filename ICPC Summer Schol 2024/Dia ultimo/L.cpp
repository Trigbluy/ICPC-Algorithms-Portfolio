#include <bits/stdc++.h>

using namespace std;

int main ()
{
    string in, rev, norm;

    set<char> vogais;
    vogais.insert('a');    
    vogais.insert('e');    
    vogais.insert('i');    
    vogais.insert('o');    
    vogais.insert('u');

    cin >> in;
    for (int i = 0; i < in.size(); i++)
        if (vogais.find(in[i]) != vogais.end())
            norm.push_back(in[i]);

    rev = norm;
    reverse(rev.begin(), rev.end());

    bool engracado = true;
    for (int i = 0; i < norm.size(); i++)
        if (rev[i] != norm[i])
            engracado = false;

    if (engracado)
        cout << 'S' << endl;
    else
        cout << 'N' << endl;

    return 0;
}   