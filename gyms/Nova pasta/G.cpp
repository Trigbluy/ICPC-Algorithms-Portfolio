#include <bits/stdc++.h>
#define maxn 2003
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define mod 1000000007

using namespace std;

struct node{
    node* next['Z'-'A'+1];
    node(){
        for(int i=0;i<='Z'-'A';i++) next[i] = NULL;
    }
};

void add(node* trie, string s){
    node* us;
    for(int i=0;i<s.size();i++){
        us = trie;
        for(int j=i;j<s.size();j++){
            if(us->next[s[j]-'A']==NULL){
                us->next[s[j]-'A'] = new node();
            }
            us = us->next[s[j]-'A'];
        }
    }
}

int query(node* root, string s){
    int resp = 0;
    node* trie;
    for(int i=0;i<s.size();i++){
        trie = root;
        if(trie->next[s[i]-'A']==NULL){
            resp = -1;
            break;
        }
        resp++;
        while(i<s.size() && trie->next[s[i]-'A']!=NULL){
            trie = trie->next[s[i]-'A'];
            i++;
        }
        i--;
    }
    return resp;
}

int main(){
    fastio;
    int n, i;
    string s;
    node* root = new node();
    cin >> s;
    add(root, s);
    cin >> n;
    for(i=0;i<n;i++){
        cin >> s;
        cout << query(root, s) << endl;
    }
    return (0);
}