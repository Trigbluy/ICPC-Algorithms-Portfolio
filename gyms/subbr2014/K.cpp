#include <bits/stdc++.h>
#define maxn 100100
using namespace std;

int v[maxn], c, n, tam, flag=0, ini, fim, seg[maxn], lazy[maxn];

void unlazy(int u, int l, int r){
    seg[u] += lazy[u];
    if(l<r){
        lazy[2*u] += lazy[u];
        lazy[(2*u)+1] += lazy[u];
    }
    lazy[u] = 0;
}

void add(int u, int l, int r, int ql, int qr, int v){
    int mid = (l+r)/2;
    if(ql<=l && qr>=r) lazy[u]+=v;
    else if(ql>r || qr<l){}
    else{
        add(2*u, l, mid, ql, qr, v);
        add((2*u)+1, mid+1, r, ql, qr, v);
    }
}

int query(int u, int l, int r, int x){
    unlazy(u, l, r);
    if(l==r) return seg[u];
    int mid = (l+r)/2;
    if(x<=mid) return query(2*u, l, mid, x);
    else return query((2*u)+1, mid+1, r, x);
}

int main () {
    int i, cont=0;
    cin >> c >> n;
    tam = c/n;
    for(i=0;i<n;i++){
        cin >> v[i];
        if(i && (v[i]-v[i-1])<tam){
            cont++;
            if(v[i-1]%tam<v[i]%tam){
                add(1, 0, tam, v[i-1]%tam+1, v[i]%tam, 1);
            }
            else{
                add(1, 0, tam, 0, v[i]%tam, 1);
                add(1, 0, tam, v[i-1]%tam+1, tam, 1);
            }
        }
    }
    if(v[0]+c-v[n-1]<tam){
        cont++;
        add(1, 0, tam, 0, v[0]%tam, 1);
        add(1, 0, tam, v[n-1]%tam+1, tam, 1);
    }
    for(i=1;i<=tam;i++){
        //cout << query(1, 0, tam, i) << endl;
        if(query(1, 0, tam, i)==cont) flag=1;
    }
    if(flag) cout << "S\n";
    else cout << "N\n";
    return 0;
}