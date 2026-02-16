#include <bits/stdc++.h>
// https://www.beecrowd.com.br/judge/en/problems/view/1446

// ####### reta horizontal ######
// ========== ponto no vertice

#define dist 0.5f

using namespace std;

class pol{
    public:
    vector <pair<float,float>> points;
    vector <pair<float,float>> eq;
    pair <int,int> info;
};

priority_queue <pair<float,int>> interssecs;
priority_queue <pair<float,int>> areas;
int main ()
{
    pol p1;
    pol p2;
    pol p3;
    int a,d;
    float b,c;
    float xmin = FLT_MAX,ymin = FLT_MAX, xmax = -FLT_MAX,ymax = -FLT_MAX;
    float colora [16];
    bool  coloraux [16] = {};
    int contador = 0;
    cin >> a;
    while(a !=0)
    {
        contador++;
        cin >> d;
        p1.info = make_pair(a,d);
        for (int k = 0; k < a; k++)
        {
            cin >> b >> c;
            p1.points.push_back(make_pair(b,c));

            if (b < xmin)
                xmin = b;
            else if (b > xmax)
                xmax = b;

            if (c < ymin)
                ymin = c;
            else if (c > ymax)
                ymax = c;
        }

        cin >> a >> d;
        p2.info = make_pair(a,d);
        for (int k = 0; k < a; k++)
        {
            cin >> b >> c;
            p2.points.push_back(make_pair(b,c));

            if (b < xmin)
                xmin = b;
            else if (b > xmax)
                xmax = b;

            if (c < ymin)
                ymin = c;
            else if (c > ymax)
                ymax = c;
        }
        cin >> a >> d;
        p3.info = make_pair(a,d);
        
        for (int k = 0; k < a; k++)
        {
            cin >> b >> c;
            p3.points.push_back(make_pair(b,c));

            if (b < xmin)
                xmin = b;
            else if (b > xmax)
                xmax = b;

            if (c < ymin)
                ymin = c;
            else if (c > ymax)
                ymax = c;
        }
        cin >> a;

        for (int i = 0; i < p1.info.first; i++)
        {
            int i2 = (i + 1) % p1.info.first;
            p1.eq.push_back( make_pair(((p1.points[i2].first-p1.points[i].first)/(p1.points[i2].second - p1.points[i].second)),
               p1.points[i].first - p1.points[i].second * (p1.points[i2].first-p1.points[i].first)/(p1.points[i2].second - p1.points[i].second)));
        }

        for (int i = 0; i < p2.info.first; i++)
        {
            int i2 = (i + 1) % p2.info.first;
            p2.eq.push_back(make_pair(((p2.points[i2].first-p2.points[i].first)/(p2.points[i2].second - p2.points[i].second)),
               p2.points[i].first - p2.points[i].second * (p2.points[i2].first-p2.points[i].first)/(p2.points[i2].second - p2.points[i].second)));
        }

        for (int i = 0; i < p3.info.first; i++)
        {
            int i2 = (i + 1) % p3.info.first;
            p3.eq.push_back(make_pair(((p3.points[i2].first-p3.points[i].first)/(p3.points[i2].second - p3.points[i].second)),
               p3.points[i].first - p3.points[i].second * ((p3.points[i2].first-p3.points[i].first)/(p3.points[i2].second - p3.points[i].second))));
        }


        for (float y = ymin; y < ymax; y += dist)
        {
            int numinter = 0;
            float x1,x2;
            bool tipo = p1.points[0].second < y;

            for (int i = 1; i < p1.info.first; i ++)
                if (((p1.points[i].second < y) != tipo) && p1.points[i].second != y)
                {
                    numinter++;
                    if (numinter == 2)
                    {
                        x2 = p1.points[i-1].second * p1.eq[i-1].first + p1.eq[i-1].second;
                        interssecs.push(make_pair(x1,p1.info.second));
                        interssecs.push(make_pair(x2,p1.info.second));
                        break;
                    }
                    x1 = p1.points[i-1].second * p1.eq[i-1].first + p1.eq[i-1].second;
                    tipo = !tipo;
                }
            if (((p1.points[0].second < y) != tipo) && p1.points[0].second != y)
            {
                numinter++;
                if (numinter == 2)
                {
                    x2 = p1.points[p1.info.first].second * p1.eq[p1.info.first].first + p1.eq[p1.info.first].second;
                    interssecs.push(make_pair(x1,p1.info.second));
                    interssecs.push(make_pair(x2,p1.info.second));
                    break;
                }
                x1 = p1.points[p1.info.first].second * p1.eq[p1.info.first].first + p1.eq[p1.info.first].second;
                tipo = !tipo;
            }

            tipo = p2.points[0].second < y;
            numinter = 0;
            for (int i = 1; i < p2.info.first; i ++)
                if (((p2.points[i].second < y) != tipo) && p2.points[i].second != y)
                {
                    numinter++;
                    if (numinter == 2)
                    {
                        x2 = p2.points[i-1].second * p2.eq[i-1].first + p2.eq[i-1].second;
                        interssecs.push(make_pair(x1,p2.info.second));
                        interssecs.push(make_pair(x2,p2.info.second));
                        break;
                    }
                    x1 = p2.points[i-1].second * p2.eq[i-1].first + p2.eq[i-1].second;
                    tipo = !tipo;
                }
            if (((p2.points[0].second < y) != tipo) && p2.points[0].second != y)
            {
                numinter++;
                if (numinter == 2)
                {
                    x2 = p2.points[p2.info.first].second * p2.eq[p2.info.first].first + p2.eq[p2.info.first].second;
                    interssecs.push(make_pair(x1,p2.info.second));
                    interssecs.push(make_pair(x2,p2.info.second));
                    break;
                }
                x1 = p2.points[p2.info.first].second * p2.eq[p2.info.first].first + p2.eq[p2.info.first].second;
                tipo = !tipo;
            }
            
            tipo = p3.points[0].second < y;
            numinter = 0;
            for (int i = 1; i < p3.info.first; i ++)
                if (((p3.points[i].second < y) != tipo) && p3.points[i].second != y)
                {
                    numinter++;
                    if (numinter == 2)
                    {
                        x2 = p3.points[i-1].second * p3.eq[i-1].first + p3.eq[i-1].second;
                        interssecs.push(make_pair(x1,p3.info.second));
                        interssecs.push(make_pair(x2,p3.info.second));
                        break;
                    }
                    x1 = p3.points[i-1].second * p3.eq[i-1].first + p3.eq[i-1].second;
                    tipo = !tipo;
                }
            if (((p3.points[0].second < y) != tipo) && p3.points[0].second != y)
            {
                numinter++;
                if (numinter == 2)
                {
                    x2 = p3.points[p3.info.first].second * p3.eq[p3.info.first].first + p3.eq[p3.info.first].second;
                    interssecs.push(make_pair(x1,p3.info.second));
                    interssecs.push(make_pair(x2,p3.info.second));
                    break;
                }
                x1 = p3.points[p3.info.first].second * p3.eq[p3.info.first].first + p3.eq[p3.info.first].second;
                tipo = !tipo;
            }


            // ========================================================================================================================
    
            if (!interssecs.empty())
            {
                float xaux = interssecs.top().first;
                int colornow = interssecs.top().second;
                coloraux [colornow] = true;
                interssecs.pop();
                while (!interssecs.empty() && xaux == interssecs.top().first);
                {
                    if (coloraux [interssecs.top().second])
                    {
                        coloraux [interssecs.top().second] = false;
                        colornow = ((colornow -interssecs.top().second) % 16 + 16) % 16;
                    }
                    else
                    {
                        coloraux [interssecs.top().second] = true;
                        colornow = ((colornow +interssecs.top().second) % 16 + 16) % 16;
                    }
                    interssecs.pop();
                } 

                while (!interssecs.empty())
                {
                    colora [colornow] += (xaux - interssecs.top().first)*dist;
                    xaux = interssecs.top().first;
                    do
                    {
                        if (coloraux [interssecs.top().second])
                        {
                            coloraux [interssecs.top().second] = false;
                            colornow = ((colornow -interssecs.top().second) % 16 + 16) % 16;
                        }
                        else
                        {
                            coloraux [interssecs.top().second] = true;
                            colornow = ((colornow +interssecs.top().second) % 16 + 16) % 16;
                        }
                        interssecs.pop();
                    }   while (!interssecs.empty() && xaux == interssecs.top().first);
                }
            }
        }

            p1.points.clear();
            p1.eq.clear();
            p2.points.clear();
            p2.eq.clear();
            p3.points.clear();
            p3.eq.clear();

        cout << "Instancia " << contador << '\n';
        for (int i = 0; i < 16; i ++)
            areas.push(make_pair(colora[i],i));
        for (int i = 0; i < 16; i++)
        {
            if (areas.top().first != 0)
                printf("%d %.2f\n",areas.top().second,areas.top().first);
            areas.pop();
        }
        for(int i = 0; i < 16;i ++)
            colora[i] = 0;
    }
}