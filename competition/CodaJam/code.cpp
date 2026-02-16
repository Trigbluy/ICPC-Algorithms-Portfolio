#include <stdio.h>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

stack <char> bloquinhos;
int n, ganhadores;

char blocos_visit[4];
char blocos_ultimo[4];

int main ()
{
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        if (bloquinhos.empty())
        {
            bloquinhos.push('F');
            bloquinhos.push('A');
            bloquinhos.push('C');
            bloquinhos.push('E'); 
        }

        for (int j = 0; j < 4; j++)
            scanf(" %c",&blocos_visit[j]);

        for (int j = 0; j < 4; j++)
        {
            blocos_ultimo[j] = bloquinhos.top();
            bloquinhos.pop();
        }
        
        bool trocado = true;
        
        for (int j = 0; j < 4; j++)
            if (blocos_ultimo[j] != blocos_visit[j])
                trocado = false;
        
        if (trocado)
            ganhadores++;
        else
        {
            for (int j = 3; j >=0; j--)
                bloquinhos.push(blocos_ultimo[j]);

            for (int j =0; j < 4; j++)
                bloquinhos.push(blocos_visit[j]);
        }
        
    }

    printf("%d\n",ganhadores);
    return 0;
}