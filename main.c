#include<stdio.h>
#include <windows.h>

void GotoXY(int x, int y);
void wall();

int main() {
    GotoXY(32, 5);
    wall();
    //대기
    int a;
    scanf("%d", a);
    return 0;
}
void wall() {
    int main[22][12] = {};
    int count = 0;

    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 12; j++) {
            main[i][j] = count;
            count++;
            if (main[i][j] % 12 == 0 || (main[i][j] + 1) % 12 == 0) {
                printf("%s ", "\u25A1");
            } else if (main[i][j] == j || main[i][j] == j + 252)  {
                printf("%s ", "\u25A1");
            } else {
                main[i][j] = printf("%s ", " ");
            }
        }
        printf("\n");
    }
}

void GotoXY(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
