#include <stdio.h>
#include <math.h>

int main ()
{
    int n;
    int values[4];
    char operation;
    int ans[2];
    int neg;

    scanf("%d",&n);
    for(int t = 0; t < n; t++)
    {
        scanf("%d / %d %c %d / %d",&values[0],&values[1], &operation, &values[2], &values [3]);
        switch (operation)
        {
            case '*':
            {
                ans[0] = values[0]*values[2];
                ans[1] = values[1]*values[3];
            }
            break;

            case '/':
            {
                ans[0] = values[0]*values[3];
                ans[1] = values[1]*values[2];
            }
            break;

            case '+':
            {
                ans[0] = values[0]*values[3] + values[1]*values[2];
                ans[1] = values[1]*values[3];
            }
            break;

            case '-':
            {
                ans[0] = values[0]*values[3] - values[1]*values[2];
                ans[1] = values[1]*values[3];
            }
            break;
        }

        neg = 1;

        if(ans[0] < 0)
        {
            neg = -1;
            ans[0]*= -1;
        }

        if(ans[1] < 0)
        {
            neg *= -1;
            ans[1]*= -1;
        }

        if(neg < 0)
            printf("-");

        printf("%d/%d = ",ans[0], ans[1]);

        if((ans[0]) > (ans [1]))
        {
            for(int k = 2; k <= (ans[1]); k++)
                if(ans[1] % k == 0)
                    if(ans[0] % k == 0)
                    {
                        ans[1]/= k;
                        ans[0]/= k;
                        k--;
                    }
        }
        else if ((ans[0]) < (ans[1]))
        {
            for(int k = 2; k <= (ans[0]); k++)
                if(ans[1] % k == 0)
                    if(ans[0] % k == 0)
                    {
                        ans[1]/= k;
                        ans[0]/= k;
                        k--;
                    }
        }
        else
        {
            ans[0] = ans[1] = 1;
        }

        if(neg < 0)
            printf("-");
        printf("%d/%d\n",ans[0],ans[1]);

    }
    return 0;
}