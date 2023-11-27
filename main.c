#include<stdio.h>
#include <windows.h>
#include <conio.h>

void GotoXY(double x, double y);
void wall();
void setBall();
void changeDirection();

int main() {
    wall(); //벽 설정
    setBall(); //공 설정
    changeDirection(); //공을 발사할 위치 설정 (keyEvent 발생)
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

void setBall() {
    GotoXY(10, 20);
    printf("\u25CF");
}

int direction = 3; //중간 값 3
void changeDirection() {
    GotoXY(10, 19);
    printf("\u2191");

    int site = getchar();
    if (site == 224) {
        site = getch();

        switch (site) {
            case 75:
                if () {}
                break;
            case 77:
                if () {}
                break;
            default:
                break;
        }
    }
}

void GotoXY(double x, double y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
