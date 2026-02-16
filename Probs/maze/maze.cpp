#include <bits/stdc++.h>
#define f first
#define s second
#define inf 10000000

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ii,ii> iii;
typedef pair<ii,iii> iiii;
priority_queue <iiii> q; // distancia, distancia pro ponto base da carimbada, x e y do ponto base da carimbada, i, j

int difx[4] = {0, 1, 0, -1};
int dify[4] = {1, 0, -1, 0};
int r, c, n;
vvi dist;
vvi m;

void bfs(ii ini){
    int i, a, b;
    q.push({{0, 0}, {{-1, -1}, {ini.f, ini.s}}});
    iiii next;
    while(!q.empty()){
        next = q.top();
        q.pop();
        if(dist[next.s.s.f][next.s.s.s]<=-next.f.f) continue;
        dist[next.s.s.f][next.s.s.s]=-next.f.f;
        for(i=0;i<4;i++){
            a = next.s.s.f+difx[i];
            b = next.s.s.s+dify[i];
            if(a<0 || a==r || b<0 || b==c) continue;
            if(dist[a][b]==inf){
                if(m[a][b]){
                    if(next.s.f.s==-1 || abs(a-next.s.f.f)==n || abs(b-next.s.f.s)==n)
                        q.push({{next.f.f, 0}, {{-1, -1}, {a, b}}});
                    else
                        q.push({{next.f.f, next.f.s-1}, {next.s.f, {a, b}}});
                }
                else{
                    if(next.s.f.s==-1 || abs(a-next.s.f.f)==n || abs(b-next.s.f.s)==n)
                        q.push({{next.f.f-1, 0}, {{a, b}, {a, b}}});
                    else
                        q.push({{next.f.f, next.f.s-1}, {next.s.f, {a, b}}});
                }
            }
        }
    }
}

int main (){
    int i, j;
    char a;
    ii fim, ini;
    cin >> r >> c >> n;
    m = vvi(r, vi(c, 0));
    dist = vvi(r, vi(c, inf));
    cin >> ini.f >> ini.s;
    ini.f--;ini.s--;
    cin >> fim.f >> fim.s;
    fim.s--;fim.f--;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> a;
            if(a=='.') m[i][j] = 1; // # = 0 (preto) e . = 1 (branco)
            dist[i][j] = inf;
        }
    }
    bfs(ini);
    cout << dist[fim.f][fim.s] << endl;
    return 0;
}