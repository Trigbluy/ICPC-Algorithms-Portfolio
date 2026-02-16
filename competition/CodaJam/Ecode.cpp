#include <bits/stdc++.h>

using namespace std;

int size;

bool oka (string &state)
{
    state [size] = state [0];

    char last = state [0];
    for (int i = 0; i < size; i++)
    {
        if (state[i+1] == last)
        {    
            state [size] = '\0';
            return false;
        }
        else
            last = state[i+1];
    }
    state [size] = '\0';
    return true;
}

int min (string &state, int a)
{
    if (oka(state))
        return 0;
    if (a >= size)
        return 1001;

    int minu = 1001;

    if (state[a] == 'P')
    {
        state[a] = 'S';
        int aux = min(state,a+1);
        if (minu >  aux + 1)
            minu = aux + 1;
        
        state[a] = 'R';
        aux = min(state,a+1);
        if (minu >  aux + 1)
            minu = aux + 1;
        
        state[a] = 'P';
        aux = min(state,a+1);
        if (minu >  aux)
            minu = aux;
    }
    else if (state[a] == 'S')
    {
        state[a] = 'P';
        int aux = min(state,a+1);
        if (minu >  aux + 1)
            minu = aux + 1;
        
        state[a] = 'R';
        aux = min(state,a+1);
        if (minu >  aux + 1)
            minu = aux + 1;
        
        state[a] = 'S';
        aux = min(state,a+1);
        if (minu >  aux)
            minu = aux;
    }
    else if (state[a] == 'R')
    {
        state[a] = 'S';
        int aux = min(state,a+1);
        if (minu >  aux + 1)
            minu = aux + 1;
        
        state[a] = 'P';
        aux = min(state,a+1);
        if (minu >  aux + 1)
            minu = aux + 1;
        
        state[a] = 'R';
        aux = min(state,a+1);
        if (minu >  aux)
            minu = aux;
    }
    return minu;
}

int main ()
{
    int t;
    int b = 0;
    cin >> t;
    while (b++ < t)
    {
        string word;
        cin >> word;
        size = word.size();
        int aux = min(word,0);
        cout << "Case #" << b << ": " << aux << '\n';
    }
    return 0;
}