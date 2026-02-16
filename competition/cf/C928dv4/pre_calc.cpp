#include <bits/stdc++.h>
#define ll long long

ll sdg (int n) {
    int s = 0;
    while (n) {
        s += n%10;
        n /= 10;
    }
    return s;
}

int main () {
    int n = 1;
    int sum = 0;

    FILE* out = fopen("pre.out","w");
    while (n <= 20000) {
        sum += sdg(n);
        fprintf(out, "mp[%d] = %ld;\n",n, sum);
        n++;
    }
    fclose(out);
    return 0;
}