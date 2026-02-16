#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

queue <pair<char,char>> cards;

int n,t,cont,p;
pair <char, char> card;
char nome[21];
int main ()
{
    cin >> t;
    while (t != 0)
    {
        
        cont = 0;
        for( int i = 0; i < t; i++)
            cards.push(make_pair('-','-'));
        for(int i = 0; i < t; i++)
        {
            cin >> card.first >> card.second >> nome;
            p = strlen(nome);
            //cout << card.first << card.second << "- " << nome;
            for(int k = 1; k < p || cards.front().first != '-'; k++)
            {
                if(cards.front().first != '-')
                    k--;
                cards.push(cards.front());
                cards.pop();
                cont--;
            }
            cards.pop();
            cards.push(card);
            cont--;
        }
        p = ((cont % t) + t) % t;
        for (int i =0; i < p; i++)
        {
            cards.push(cards.front());
            cards.pop();
        }
        for(int i = 1; i <t; i++)
        {
            cout << cards.front().first << cards.front().second << " ";
            cards.pop();
        }
        cout << cards.front().first << cards.front().second;
            cards.pop();
        cout << endl;
        cin >> t;
    }
    return 0;
}