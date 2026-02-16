#include <bits/stdc++.h>

using namespace std;

map <string, int> mp;
map <string, int> vis;
vector <string> v;

int main(){
    int a, b, i;
    string s = "a";
    getline(cin, s);
    while(s!="------"){
        a = 0 , b = 0;
        for (i = 0; i < s.size() && s[i] != ' '; i++) {
            a*= 10;
            a+= s[i] - '0';
        }
        for (i++ ; i < s.size() && s[i] != ' '; i++) {
            b*= 10;
            b+= s[i] - '0';
        }
        string aux;
        for (i++; i <s.size();i++)
            aux.push_back(s[i]);
        cout << a << " " << b << endl;
        mp[aux] -= (b-a);
        if(!vis[aux]){
            vis[aux] = 1;
            v.push_back(aux);
        }
        getline(cin, s);
    }
    getline(cin, s);
    while(s!="======"){
        a = 0 , b = 0;
        for (i = 0; i < s.size() && s[i] != ' '; i++) {
            a= 10;
            a+= s[i] - '0';
        }
        for (i++ ; i < s.size() && s[i] != ' '; i++) {
            b= 10;
            b+= s[i] - '0';
        }
        string aux;
        for (i++; i <s.size();i++)
            aux.push_back(s[i]);
        mp[aux] += (b-a);
        if(!vis[aux]){
            vis[aux] = 1;
            v.push_back(aux);
        }
        cout << a << b << aux;
        getline(cin, s);
    }
    sort(v.begin(), v.end());
    for(i=0;i<v.size();i++){
        if(mp[v[i]]>0) cout << v[i] << " +" << mp[v[i]] << endl;
        else if(mp[v[i]]<0) cout << v[i] << " " << mp[v[i]] << endl;
    }
    return (0);
}