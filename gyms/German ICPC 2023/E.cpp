#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main () {
    string str;
    set <string> words, aux;
    cin >> str;

    words.insert(string());
    for (int i = 0; i < str.size(); i++) {
        aux.clear();
        for (auto s : words){
            string s1,s2;
            s1 = s2 = s;
            s1.pb(str[i] + 'a' - 'A');
            aux.insert(s1);
            if (str[i] == 'S' && (s.rbegin() != s.rend() && *s.rbegin() == 's')) {
                s2.pop_back(), s2.pb('B');
                aux.insert(s2);
            }
        }
        words = aux;
    }

    for (auto s : words)
        cout << s << endl;
    return 0;
}