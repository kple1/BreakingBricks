#include<stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main() {
    char main[11][6] = {};

    int count = 0;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 6; j++) {
            main[i][j] = count;
            count++;
            //if (main[i][j] == 0 || main[i][j] == 5 || main[i][j] == 60 || main[i][j] == 65) main[i][j] = ' ';
            if (main[i][j] % 6 == 0 || (main[i][j] + 1) % 6 == 0) main[i][j] = L'■';
            else if (main[i][j] == j || main[i][j] == j + 60) main[i][j] = L'■';
            else main[i][j] = ' ';
            printf(L"%s ", main[i][j]);
        }
        printf("\n");
    }
    return 0;
}