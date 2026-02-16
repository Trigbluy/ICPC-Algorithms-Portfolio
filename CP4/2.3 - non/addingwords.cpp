#include <bits/stdc++.h>

using namespace std;

map <string, int> dic;

int main ()
{
    string command;
    while (cin >> command)
    {
        if (command == "def")
        {
            string var;
            int val;
            cin >> var >> val;
            if (dic.find(var) == dic.end())
                dic.insert(make_pair(var,val));
            else
                dic[var] = val;
        }
        else if (command == "calc")
        {
            string b, op, finded = "";
            int result, value;
            cin >> b;
            cout << b << ' ';
            if (dic.find(b) == dic.end())
                finded = "unknown";
            else
                result = dic[b];
            cin >> op;
            cout << op << ' ';
            while(op != "=")
            {
                if (op == "+")
                {
                    cin >> b;
                    cout << b << ' ';
                    if (dic.find(b) == dic.end())
                        finded = "unknown";
                    else
                        result += dic[b];
                }
                else
                {
                    cin >> b;
                    cout << b << ' ';
                    if (dic.find(b) == dic.end())
                        finded = "unknown";
                    else
                        result -= dic[b];
                }
                cin >> op;
                cout << op << ' ';
            }
            if (finded == "")
                for(auto a : dic)
                {
                    if(a.second == result)
                    {
                        finded = a.first;
                        break;
                    }
                }

            if (finded == "")
                cout << "unknown" << endl;
            else
                cout << finded << endl;
        }
        else if (command == "clear")
            dic.clear();
    }
    return 0;
}