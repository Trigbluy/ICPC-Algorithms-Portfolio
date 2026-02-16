#include <bits/stdc++.h>

int main () {
    int a, b, cnt = 1;
    FILE* ans = fopen("L.out", "r");
    FILE* gab = fopen("C:\\Users\\dany1\\OneDrive\\Documentos\\Coding\\Learning\\gyms\\Sub BR 2018\\contest_tests\\L\\output\\L_gab.out", "r");
    for (;fscanf(ans, " %d ", &a) ; cnt++) {
        fscanf(gab, " %d ", &b);
        if (a != b) {
            printf("Erro in line %d ( %d, %d)\n", cnt, a, b);
            break;
        }
    }
    fclose(ans);
    fclose(gab);
    return 0;
}