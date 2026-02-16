#include <bits/stdc++.h>

using namespace std;

// https://vjudge.net/problem/UVA-10815

set <string> dict;
string word;

int main ()
{
    //ios_base :: sync_with_stdio(true);
    //cin.tie(1);
    //cout.tie(1);
    char a;
    bool res;
    int pos = 0;

    while (scanf("%c",&a) == 1)
    {
        //printf("%d ",pos);
        if ('a' <= a && a <= 'z')
        {
            //word.push_back(a);
            word[pos] = a;
            pos++;
        }
        else if ('A' <= a && a <= 'Z')
        {
            a = tolower(a);
            //word.push_back(a);
            word[pos] = a;
            pos++;
        }
        else if (a == '|')
            break;
        else if (pos != 0)
        {
            //word.push_back('\0');
            word[pos] = '\0';
            dict.insert(word.c_str());
            word.clear();
            pos = 0;
        }
    }
    for (auto b : dict)
        cout << b << '\n';
    //cout << dict.size();

    return 0;
}