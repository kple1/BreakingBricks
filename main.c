#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void GotoXY(double x, double y);
void wall();
void setFloor();

int main() {
    wall(); //벽 설정
    setFloor(); //바닥 설정
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
                printf("%s ", " ");
            }
        }
        printf("\n");
    }
}

void setFloor() {
    GotoXY(9, 20);
    printf("_____");

    char c;
    while (1) {
        if (_kbhit()) {
            c = getch();
            if (c == -32) {
                c = getch();
                switch (c) {
                    case LEFT:
                        break;
                }
            }
        }
    }
}

void GotoXY(double x, double y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
