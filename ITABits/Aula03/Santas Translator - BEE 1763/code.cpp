#include <bits/stdc++.h>

using namespace std;

// https://www.beecrowd.com.br/judge/en/problems/view/1763?origem=1

map <string,string> HpCrsms;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string anal, word;
    bool wh;
    string a1, a2;
    auto end = HpCrsms.end();

    // vou inserir os casos no site por facilidade
    HpCrsms.insert(make_pair("brasil","Feliz Natal!"));
    HpCrsms.insert(make_pair("alemanha","Frohliche Weihnachten!"));
    HpCrsms.insert(make_pair("austria","Frohe Weihnacht!"));
    HpCrsms.insert(make_pair("coreia","Chuk Sung Tan!"));
    HpCrsms.insert(make_pair("espanha","Feliz Navidad!"));
    HpCrsms.insert(make_pair("grecia","Kala Christougena!"));
    HpCrsms.insert(make_pair("estados-unidos","Merry Christmas!"));
    HpCrsms.insert(make_pair("inglaterra","Merry Christmas!"));
    HpCrsms.insert(make_pair("australia","Merry Christmas!"));
    HpCrsms.insert(make_pair("portugal","Feliz Natal!"));
    HpCrsms.insert(make_pair("suecia","God Jul!"));
    HpCrsms.insert(make_pair("turquia","Mutlu Noeller"));
    HpCrsms.insert(make_pair("argentina","Feliz Navidad!"));
    HpCrsms.insert(make_pair("chile","Feliz Navidad!"));
    HpCrsms.insert(make_pair("mexico","Feliz Navidad!"));
    HpCrsms.insert(make_pair("antardida","Merry Christmas!"));
    HpCrsms.insert(make_pair("canada","Merry Christmas!"));
    HpCrsms.insert(make_pair("irlanda","Nollaig Shona Dhuit!"));
    HpCrsms.insert(make_pair("belgica","Zalig Kerstfeest!"));
    HpCrsms.insert(make_pair("italia","Buon Natale!"));
    HpCrsms.insert(make_pair("libia","Buon Natale!"));
    HpCrsms.insert(make_pair("siria","Milad Mubarak!"));
    HpCrsms.insert(make_pair("marrocos","Milad Mubarak!"));
    HpCrsms.insert(make_pair("japao","Merii Kurisumasu!"));
    

    while(std:: cin >> anal)
    {
        auto a = HpCrsms.find(anal);
        if (a != end)
            cout << a->second << '\n';
        else
            cout << "--- NOT FOUND ---\n";
    }
    return 0;
}