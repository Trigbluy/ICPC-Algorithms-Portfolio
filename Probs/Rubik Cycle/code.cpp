#include <bits/stdc++.h>

using namespace std;

// https://www.beecrowd.com.br/judge/en/problems/view/1232

enum rotation {up,back,down,front,right,left};
class peca
{
    public:
        int valor;
        rotation rot ; // 2 eixos de rotação x,y - sentido horario +
};

peca cubo[3][3][3];
peca cuboaux[3][3][3];
deque <int> spin;
queue <pair<int,peca>> trades;

int main ()
{

    for (int i = 0; i < 27; i ++)
    {
        (&cubo[0][0][0]+i)->valor = i;
        (&cubo[0][0][0]+i)->rot = up;
    }
    char move;
    int ntd, quant;
    bool equal;
    
    while (scanf("%c",&move) == 1)
    {
        //cout << "trav";
        switch (move)
        {
            case 'R':
            {
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                int i = 0, k = 0;
                for (; i < 2; i++)
                    spin.push_back(cubo[2][k][i].valor);
                //cout <<"p";
                for (; k < 2; k ++)
                    spin.push_back(cubo[2][k][i].valor);
                for (; i > 0; i --)
                    spin.push_back(cubo[2][k][i].valor);
                for (; k > 0; k --)
                    spin.push_back(cubo[2][k][i].valor);
                //cout << '\n' << "size: " << spin.size() << '\n';

                for(int j = 0; j < 2; j ++)
                {
                    spin.push_back(spin.front());
                    spin.pop_front();
                }
                //i = k = 0;
                //cout << "s";
                
                for (; i < 2; i++)
                {
                    cubo[2][k][i].valor = spin.front();
                    switch (cubo[2][k][i].rot)
                    {
                        case up:
                            cubo[2][k][i].rot = front;
                            break;
                        case front:
                            cubo[2][k][i].rot = down;
                            break;
                        case down:
                            cubo[2][k][i].rot = back;
                            break;
                        case back:
                            cubo[2][k][i].rot = up;
                            break;
                    } 
                    spin.pop_front();
                }
                for (; k < 2; k ++)
                {
                    cubo[2][k][i].valor = spin.front();
                    switch (cubo[2][k][i].rot)
                    {
                        case up:
                            cubo[2][k][i].rot = front;
                            break;
                        case front:
                            cubo[2][k][i].rot = down;
                            break;
                        case down:
                            cubo[2][k][i].rot = back;
                            break;
                        case back:
                            cubo[2][k][i].rot = up;
                            break;
                    }
                    spin.pop_front();
                }
                for (; i > 0; i --)
                {
                    cubo[2][k][i].valor = spin.front();
                    switch (cubo[2][k][i].rot)
                    {
                        case up:
                            cubo[2][k][i].rot = front;
                            break;
                        case front:
                            cubo[2][k][i].rot = down;
                            break;
                        case down:
                            cubo[2][k][i].rot = back;
                            break;
                        case back:
                            cubo[2][k][i].rot = up;
                            break;
                    }
                    spin.pop_front();
                }
                for (; k > 0; k --)
                {
                    cubo[2][k][i].valor = spin.front();
                    switch (cubo[2][k][i].rot)
                    {
                        case up:
                            cubo[2][k][i].rot = front;
                            break;
                        case front:
                            cubo[2][k][i].rot = down;
                            break;
                        case down:
                            cubo[2][k][i].rot = back;
                            break;
                        case back:
                            cubo[2][k][i].rot = up;
                            break;
                    }
                    spin.pop_front();
                }
                //cout << spin.size();
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                break;
            }
            /*
            case 'r':
            {
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                int i = 0, k = 0;
                for (; i < 2; i++)
                    spin.push_back(cubo[2][k][i]);
                //cout <<"p";
                for (; k < 2; k ++)
                    spin.push_back(cubo[2][k][i]);
                for (; i > 0; i --)
                    spin.push_back(cubo[2][k][i]);
                for (; k > 0; k --)
                    spin.push_back(cubo[2][k][i]);
                //cout << '\n' << "size: " << spin.size() << '\n';

                for(int j = 0; j < 2; j ++)
                {
                    spin.push_front(spin.back());
                    spin.pop_back();
                }
                //i = k = 0;
                //cout << "s";
                
                for (; i < 2; i++)
                {
                    cubo[2][k][i] = spin.front();
                    spin.pop_front();
                }
                for (; k < 2; k ++)
                {
                    cubo[2][k][i] = spin.front();
                    spin.pop_front();
                }
                for (; i > 0; i --)
                {
                    cubo[2][k][i] = spin.front();
                    spin.pop_front();
                }
                for (; k > 0; k --)
                {
                    cubo[2][k][i] = spin.front();
                    spin.pop_front();
                }
                //cout << spin.size();
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                break;
            }

            case 'L':
            {
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                int i = 0, k = 0;
                for (; i < 2; i++)
                    spin.push_back(cubo[0][k][i]);
                //cout <<"p";
                for (; k < 2; k ++)
                    spin.push_back(cubo[0][k][i]);
                for (; i > 0; i --)
                    spin.push_back(cubo[0][k][i]);
                for (; k > 0; k --)
                    spin.push_back(cubo[0][k][i]);
                //cout << '\n' << "size: " << spin.size() << '\n';

                for(int j = 0; j < 2; j ++)
                {
                    spin.push_front(spin.back());
                    spin.pop_back();
                }
                //i = k = 0;
                //cout << "s";
                
                for (; i < 2; i++)
                {
                    cubo[0][k][i] = spin.front();
                    spin.pop_front();
                }
                for (; k < 2; k ++)
                {
                    cubo[0][k][i] = spin.front();
                    spin.pop_front();
                }
                for (; i > 0; i --)
                {
                    cubo[0][k][i] = spin.front();
                    spin.pop_front();
                }
                for (; k > 0; k --)
                {
                    cubo[0][k][i] = spin.front();
                    spin.pop_front();
                }
                //cout << spin.size();
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                break;
            }

            case 'l':
            {
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                int i = 0, k = 0;
                for (; i < 2; i++)
                    spin.push_back(cubo[0][k][i]);
                //cout <<"p";
                for (; k < 2; k ++)
                    spin.push_back(cubo[0][k][i]);
                for (; i > 0; i --)
                    spin.push_back(cubo[0][k][i]);
                for (; k > 0; k --)
                    spin.push_back(cubo[0][k][i]);
                //cout << '\n' << "size: " << spin.size() << '\n';

                for(int j = 0; j < 2; j ++)
                {
                    spin.push_back(spin.front());
                    spin.pop_front();
                }
                //i = k = 0;
                //cout << "s";
                
                for (; i < 2; i++)
                {
                    cubo[0][k][i] = spin.front();
                    spin.pop_front();
                }
                for (; k < 2; k ++)
                {
                    cubo[0][k][i] = spin.front();
                    spin.pop_front();
                }
                for (; i > 0; i --)
                {
                    cubo[0][k][i] = spin.front();
                    spin.pop_front();
                }
                for (; k > 0; k --)
                {
                    cubo[0][k][i] = spin.front();
                    spin.pop_front();
                }
                //cout << spin.size();
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                break;
            }
            */
            case 'U':
            {
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                int i = 0, k = 0;
                for (; i < 2; i++)
                    spin.push_back(cubo[k][i][2].valor);
                //cout <<"p";
                for (; k < 2; k ++)
                    spin.push_back(cubo[k][i][2].valor);
                for (; i > 0; i --)
                    spin.push_back(cubo[k][i][2].valor);
                for (; k > 0; k --)
                    spin.push_back(cubo[k][i][2].valor);
                //cout << '\n' << "size: " << spin.size() << '\n';

                for(int j = 0; j < 2; j ++)
                {
                    spin.push_back(spin.front());
                    spin.pop_front();
                }
                //i = k = 0;
                //cout << "s";
                
                for (; i < 2; i++)
                {
                    cubo[k][i][2].valor = spin.front();
                    switch (cubo[k][i][2].rot)
                    {
                        case right:
                            cubo[2][k][i].rot = front;
                            break;
                        case front:
                            cubo[2][k][i].rot = left;
                            break;
                        case left:
                            cubo[2][k][i].rot = back;
                            break;
                        case back:
                            cubo[2][k][i].rot = right;
                            break;
                    }
                    spin.pop_front();
                }
                for (; k < 2; k ++)
                {
                    cubo[k][i][2].valor = spin.front();
                    switch (cubo[k][i][2].rot)
                    {
                        case right:
                            cubo[2][k][i].rot = front;
                            break;
                        case front:
                            cubo[2][k][i].rot = left;
                            break;
                        case left:
                            cubo[2][k][i].rot = back;
                            break;
                        case back:
                            cubo[2][k][i].rot = right;
                            break;
                    }
                    spin.pop_front();
                }
                for (; i > 0; i --)
                {
                    cubo[k][i][2].valor = spin.front();
                    switch (cubo[k][i][2].rot)
                    {
                        case right:
                            cubo[2][k][i].rot = front;
                            break;
                        case front:
                            cubo[2][k][i].rot = left;
                            break;
                        case left:
                            cubo[2][k][i].rot = back;
                            break;
                        case back:
                            cubo[2][k][i].rot = right;
                            break;
                    }
                    spin.pop_front();
                }
                for (; k > 0; k --)
                {
                    cubo[k][i][2].valor = spin.front();
                    switch (cubo[k][i][2].rot)
                    {
                        case right:
                            cubo[2][k][i].rot = front;
                            break;
                        case front:
                            cubo[2][k][i].rot = left;
                            break;
                        case left:
                            cubo[2][k][i].rot = back;
                            break;
                        case back:
                            cubo[2][k][i].rot = right;
                            break;
                    }
                    spin.pop_front();
                }
                //cout << spin.size();
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                break;
            }

            case '\n':
            {
                //cout << "S";

                for(int i = 0; i < 27; i ++)
                    if ( (&cubo[0][0][0] + i)->valor != i || (&cubo[0][0][0] + i)->rot != up || ((&cubo[0][0][0] + i)->rot != up) || ((&cubo[0][0][0] + i)->rot != up))
                        for (int k = 0; k < 27; k ++)
                            if ((&cubo[0][0][0] + k)->valor == i)
                            {
                                peca final = [k,(&cubo[0][0][0] + k)->rot];
                                trades.push(make_pair(i,final));
                                break;
                            }
                //cout << *(&cubo[0][0][0] + 20);
                //for (int i = 0; i < 27; i++)
                    //cout << *(&cubo[0][0][0] + i) << ' ';
                ntd = trades.size();

                for (int i = 0; i < ntd; i++)
                {
                    cout << trades.front().first.valor << " -> " << trades.front().second.valor << '\n'; 
                    trades.push(trades.front());
                    trades.pop();
                }

                
                quant = 0;
                //cout << 's';
                for (int i = 0; i < 27; i ++)
                    (&cubo[0][0][0]+i)->valor = i;
                for (int i = 0; i < 27; i ++)
                    (&cuboaux[0][0][0]+i)->valor = i;
                //cout << "im";
                do
                {
                    for (int i = 0; i < ntd; i ++)
                    {
                        *(&cuboaux[0][0][0] + trades.front().second.valor) = *(&cubo[0][0][0] + trades.front().first.valor);
                        trades.push(trades.front());
                        trades.pop();
                    }

                    for (int i = 0; i < ntd; i ++)
                    {
                        *(&cubo[0][0][0] + trades.front().second.valor) = *(&cuboaux[0][0][0] + trades.front().second.valor);
                        trades.push(trades.front());
                        trades.pop();
                    }

                    for (int i = 0; i < 27; i++)
                        cout << (&cubo[0][0][0] + i)->valor << ' ';
                    cout << '\n';

                    equal = true;

                    for (int i = 0; i < ntd; i++)
                    {
                        if ((&cubo[0][0][0] + trades.front().first.valor)->valor != trades.front().first.valor)
                            equal = false;

                        trades.push(trades.front());
                        trades.pop();
                    }
                    //cout << quant;
                    quant++;
                } while (!equal);
                
                cout << quant << '\n';
                for (int i = 0; i < ntd; i ++)
                    trades.pop();
                break;
            }
            //cout << "sai" << '\n'; 
        }
    }
    cout << '\n';

    return 0;
}