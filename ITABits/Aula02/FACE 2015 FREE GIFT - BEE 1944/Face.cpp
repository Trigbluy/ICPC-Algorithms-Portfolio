#include <iostream>
#include <stack>
using namespace std;
int n;
stack<char> blocks;
char temp[4];
int gift = 0;
int rec;
int main ()
{
    cin >> n;

    blocks.push('F');
    blocks.push('A');
    blocks.push('C');
    blocks.push('E');
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < 4; i++)
        {
            char a;
            scanf(" %c",&a);
            temp[i] = a;
        }

        rec = -1;

        for(int i = 0; i < 4; i++)
            if (temp[i] == blocks.top())
            {
                blocks.pop();
                rec++; 
                if (i == 3)
                {
                    gift++;
                    rec = 4;
                }
            }
            else
                break;
        
        for(int i = rec; i >= 0; i--)
            blocks.push(temp[i]);
        if(rec != 4)
            for(int i = 0; i < 4; i++)
                blocks.push(temp[i]);

    }

    cout << gift;
    return 0;
}