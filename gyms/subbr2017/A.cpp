#include <bits/stdc++.h>
#define maxn 100000
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

struct node{
    int notes[9], lazy;
    node(){
        lazy = 0;
        for(int i=0;i<9;i++) notes[i] = 0;   
    }
    node operator+ (node p){
        node resp = node();
        for(int i=0;i<9;i++){
            resp.notes[i] = notes[i]+p.notes[i];
        }
        return resp;
    }
    node operator- (node p){
        node resp = node();
        for(int i=0;i<9;i++){
            resp.notes[i] = notes[i]-p.notes[i];
        }
        return resp;
    }
};

node seg[4*maxn], k;

void build(int u, int l, int r){
    seg[u] = node();
    seg[u].notes[1] = r-l+1;
    if(l!=r){
        int mid = (l+r)/2;
        build(2*u, l, mid);
        build((2*u)+1, mid+1, r);
    }
}

void unlazy(int u, int l, int r){
    if(!seg[u].lazy) return;
    node aux = node();
    seg[u].lazy %= 9;
    for(int i=0;i<9;i++){
        aux.notes[i] = seg[u].notes[(i-seg[u].lazy+9)%9];
    }
    if(l!=r){
        seg[2*u].lazy += seg[u].lazy;
        seg[(2*u)+1].lazy += seg[u].lazy;
    }
    seg[u] = aux;
}

node query(int u, int l, int r, int ql, int qr){
    unlazy(u, l, r);
    if(ql<=l && qr>=r) return seg[u];
    int mid = (l+r)/2;
    k = node();
    if (ql <= mid)
        k = query(2*u, l, mid, ql, qr);
    if (mid+1 <= qr)
        k = k + query((2*u)+1, mid+1, r, ql, qr);
    return k;
}

node update(int u, int l, int r, int ql, int qr, int val){
    if(ql<=l && qr>=r){
        node resp = node();
        resp = resp - seg[u];
        seg[u].lazy += val;
        unlazy(u, l, r);
        resp = resp + seg[u];
        return resp;
    }
    unlazy(u, l, r);
    int mid = (l+r)/2;
    node alter = node();
    if (ql <= mid)
        alter = update(2*u, l, mid, ql, qr, val);
    if (mid + 1 <= qr)
        alter = alter + update((2*u)+1, mid+1, r, ql, qr, val);
    seg[u] = seg[u] + alter;
    return alter;
}

int main () {
    fastio;
    int n, q, i, a, b, j, max_num, max_val;
    node f;
    cin >> n >> q;
    build(1, 0, n-1);
    for(i=0;i<q;i++){
        cin >> a >> b;
        f = query(1, 0, n-1, a, b);
        max_num = 0;
        for(j=0;j<9;j++){
            if(f.notes[j]>=max_num){
                max_num = f.notes[j];
                max_val = j;
            }
        }
        update(1, 0, n-1, a, b, max_val);
    }
    for(j=0;j<n;j++){
        f = query(1, 0, n-1, j, j);
        for(i=0;i<9;i++){
            if(f.notes[i]){
                max_val = i;
                break;
            }
        }
        cout << max_val << endl;
    }
    return 0;
}