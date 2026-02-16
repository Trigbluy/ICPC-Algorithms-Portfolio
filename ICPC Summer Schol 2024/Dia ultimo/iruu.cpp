#include <bits/stdc++.h>
using namespace std;
int main (){
    int vet[10] = { 1,2,3,4,5,6,7,8,9,4};
    int n = 10;


    int maximo = 0;
    for (int i = 0; i < n; i++){
        if (vet[i]>maximo){
            maximo = vet[i];
        }
    }
    cout << maximo << endl;
    return 0;
}