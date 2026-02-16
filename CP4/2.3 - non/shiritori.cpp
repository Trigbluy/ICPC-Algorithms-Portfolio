#include <bits/stdc++.h>

using namespace std;

unordered_set <string> dic;
int main ()
{
    int n;
    string word;
    cin >> n;

    char lastchar;

    n;
    cin >> word;
    lastchar = word[word.size() - 1];
    dic.insert(word);
    
    for ( int i = 1; i < n; i++)
    {
        cin >> word;
        if (word[0] != lastchar || dic.find(word) != dic.end())
        {
            cout << "Player " << i%2 + 1 << " lost" << endl;
            return 0;
        }
        dic.insert(word);
        lastchar = word[word.size() - 1];
    }

    cout << "Fair Game" << endl;

    return 0;
}