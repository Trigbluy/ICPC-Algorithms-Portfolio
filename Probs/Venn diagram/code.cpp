#include <bits/stdc++.h>

using namespace std;

struct equationes
{
    float a,b,c; // ay + bx + c = 0
};

class pol
{
    public:
        vector <pair<float,float>> points;
        vector <equationes> eq;
        pair <int,int> info; //quantVertices, quantCor

    /*pol(vector <pair<float,float>> _points, vector <equationes> _eq, pair <int,int> info)
    {

    }*/
};

pol poligonos[3];
set <pair <float,float>> viras;

int main ()
{
    int nPontos = 1;
    int cor;
    
    //ler input
    while (true)
    {
        for(int i = 0; i < 3 ; i++)
        {
            cin >> nPontos;
            if (nPontos == 0)
                return 0;

            cin >> cor;
            poligonos[i].info = make_pair (nPontos,cor);

            int a,b;
            for(int k = 0; k < poligonos[i].info.first; k ++)
            {
                cin >> a >> b;
                poligonos[i].points.push_back(make_pair(a,b));
                viras.insert(make_pair(a,b));
            }

            for (int k = 0; k < poligonos[i].info.first; k++)
            {
                equationes aux;
                aux.a = poligonos[i].points[k].first - poligonos[i].points[(k+1) % 16].first;
                aux.b = poligonos[i].points[(k + 1)% 16].second - poligonos[i].points[k].second;
                aux.c = -aux.a*poligonos[i].points[k].second - poligonos[i].points[k].first*aux.b;
                poligonos[i].eq.push_back(aux);
            }
        }
        
        for (int i = 0; i < poligonos[0].info.first; i ++)
        {
            for (int k = 1; k < 3; k ++)
            {
                pair<float,float> p1 = poligonos[0].points[i],p2 = poligonos[0].points[(i+1)%16],p3 = poligonos[k].points[i],p4 = poligonos[k].points[(i+1)%16];

                if(((((p1.first < (p3.first < p4.first)? p3.first:p4.first) != (p2.first < (p3.first < p4.first)? p3.first:p4.first)) 
                && ((p1.first < (p3.second < p4.second)? p3.second:p4.second) != (p2.second < (p3.second < p4.second)? p3.second:p4.second)))
                || (()))
                || ((((p3.first < p1.first) == (p1.first < p4.first)) && ((p3.second < p1.second) == (p1.second < p4.second)) )
                && ((poligonos[0].eq[i].a*p3.second + poligonos[0].eq[i].b*p3.first + poligonos[0].eq[i].c > 0) != 
                    (poligonos[0].eq[i].a*p4.second + poligonos[0].eq[i].b*p4.first + poligonos[0].eq[i].c > 0))))
                {
                    
                }

            }
        }

    }
}