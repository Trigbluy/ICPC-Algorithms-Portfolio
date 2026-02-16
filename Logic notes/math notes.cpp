#include <bits/stdc++.h>

using namespace std;

int mdc (int n1, int n2) // Algoritimo de euclides
{
    int rest;

    do
    {
        rest = n1 % n2;
        n1 = n2;
        n2 = rest;
    } while (rest != 0);

    return n1;
}