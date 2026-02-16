#include <stdio.h>
#include <queue>
using namespace std;

queue<int> qe;

int main ()
{
    int k;
    scanf("%d",&k);
    while (k != 0)
    {
        for(int i=1;i<=k;i++)
            qe.push(i);
        printf("Discarded cards:");
        int cont=0;
        int lc;
        for(int i=0;i<k-1;i++)
        {
            printf(" %d%c",qe.front(),i == k-2 ? '\n': ',');
            qe.pop();
            lc = qe.front();
            qe.push(qe.front());
            qe.pop();
            cont++;            
        }
        printf("Remaining card: %d\n",lc);
        cont = 0;
        scanf(" %d",&k);
        qe.pop();
    }

    return 0;
}
