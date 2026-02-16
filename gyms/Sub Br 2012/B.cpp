#include <bits/stdc++.h>
#define maxn 1008
using namespace std;

typedef struct{
    double a, b, c;
}ret;

typedef struct{
    double x, y;
}ponto;

typedef struct{
    ponto p;
    ret r;
}aleta;

aleta v[maxn];
ret bar[2];
double num[2];

double dist(ponto s, ponto t){
    return abs(sqrt(((s.x-t.x)*(s.x-t.x))+((s.y-t.y)*(s.y-t.y))));
}

double distret(ponto s, ret t){
    return abs(((t.a*s.x)+(t.b*s.y)+t.c)/sqrt((t.a*t.a)+(t.b*t.b)));
}

int main () {
    int n, h, i;
    double resp, anp, yk, xi, xf, yi, yf, l;
    while(scanf("%d %lf %d", &n, &l, &h)!=EOF){
        resp = l;
        num[1] = l;
        num[0] = 0;
        bar[0].a = 1;
        bar[0].b = 0;
        bar[0].c = -l;
        bar[1].a = 1;
        bar[1].b = 0;
        bar[1].c = 0;
        for(i=0;i<n;i++){
            xi = num[i&1];
            cin >> yi >> xf >> yf;
            v[i].p.x = xf;
            v[i].p.y = yf;
            //calcula ret
            v[i].r.a = yf-yi;
            v[i].r.b = xi-xf;
            v[i].r.c = (xf*yi)-(xi*yf);
        }
        for(i=0;i<n-1;i++){
            resp = min(resp, distret(v[i].p, bar[i&1]));
            anp = (v[i+1].r.a*v[i].p.y) - (v[i+1].r.b * v[i].p.x);
            yk = ((v[i+1].r.a*anp)-(v[i+1].r.c*v[i+1].r.b))/((v[i+1].r.a*v[i+1].r.a)+(v[i+1].r.b*v[i+1].r.b));
            if(yk<v[i+1].p.y){
                resp = min(resp, dist(v[i].p, v[i+1].p));
            }
            else{
                resp = min(resp, distret(v[i].p, v[i+1].r));
            }
        }
        resp = min(resp, distret(v[n-1].p, bar[(n-1)&1]));
        printf("%.2lf\n", resp);
    }
    return 0;
}