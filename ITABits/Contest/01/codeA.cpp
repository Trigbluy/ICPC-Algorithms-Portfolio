#include <iostream>
using namespace std;
int main ()
{
    int t, n;
    int inst[100];
    int pos, ord;
    string instr;
    cin >> t;
    for(int k =0; k < t; k++)
    {
        cin >> n;
        pos = 0;
        for(int i = 0; i <n; i++)
        {
            cin >> instr;
            if(instr == "LEFT")
            {
                inst[i] = -1;
                pos--;
            }
            else if (instr == "RIGHT")
            {
                inst[i] = +1;
                pos++;
            }
            else
            {
                cin >> instr;
                cin >> ord;
                inst[i] = inst[ord-1];
                pos+= inst[ord-1];
            }
        }
        cout << pos << endl;
    }
}