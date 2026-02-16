#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

typedef vector<int> vi;

vi v;
int flag;

int busca(int x){
    int ini = 0, fim = v.size()-1, med;
    while(ini<fim){
        med = (ini+fim)/2;
        if(v[med]<x) ini = med+1;
        else if(v[med]==x){
            flag = 1;
            ini = med+1;
        }
        else{
            fim = med;
        }
    }
    if(v[ini]==x) flag=1;
    if(v[ini]<=x) ini++;
    return ini;
}

int main(){
    fastio;
    int n, q, i, a, j, b, c, k;
    cin >> n >> q;
    for(i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(i=0;i<q;i++){
        cin >> a;
        if(a==1){
            cin >> b;
            flag = 0;
            j = busca(b);
            if(!flag){
                if(j==v.size()) v.push_back(b);
                else v[j] = b;
            }
        }
        else{
            cin >> b >> c;
            j = busca(b-1);
            k = busca(c);
            cout << k-j << endl;
        }
    }
    return (0);
}