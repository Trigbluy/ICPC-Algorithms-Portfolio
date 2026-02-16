#include <stdio.h>

int main ()
{

    int a = 0;
    bool prob = false;
    char p;
    char text[1001];
    while(scanf("%s",text) != -1)
    {
        for (int i = 0;;i++)
        {
            p = text[i];
            if(p == '(')
                a++;
            else if (p == ')')
            {
                a--;
                if (a < 0)
                {
                    prob = true;
                    break;
                }
            }
                else if (p == '\0')
                break;
        }

        if(prob || a != 0)
                    printf("incorrect\n");
                else
                    printf("correct\n");
                a = 0;
    }

    return 0;
}