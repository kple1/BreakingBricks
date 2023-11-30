#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77

#define top 1
#define leftWall 60
#define RightWall 95
#define floor 31

void GotoXY(int x, int y);
void shoot();
void changeAngle_Top();
void changeAngle_Left();
void changeAngle_Right();
void keyListener(); //break 대체 할 system 만들어지면 함수 사용
void systemSetting();
void showTitle();
void reset();

int floorX = 77;
int floorY = 31;

int ballX = 80;
int ballY = 30;

int changeDirection = 0;
int startData = 78;

int main() {
    systemSetting();
    showTitle();

    char c;
    while (1) {
        if (_kbhit()) {
            c = _getch();
            if (c == -32) {
                c = _getch();
                if (floorX == 60 || floorX == 95) break; //발판이 벽에 닿으면
                switch (c) {
                    case LEFT:
                        GotoXY(floorX, floorY);
                        printf("      ");
                        floorX -= 1;
                        GotoXY(floorX, floorY);
                        printf("______");
                        break;
                    case RIGHT:
                        GotoXY(floorX, floorY);
                        printf("      ");
                        floorX += 1;
                        GotoXY(floorX, floorY);
                        printf("______");
                        break;
                }
            }
        }

        /**
         * 첫 시작이 N ~ 78 , 76 ~ 0 만약 77일시 바로 공이 발사됨을 방지하기 위하여, 변수로 따로 지정.
         * 만약 시작하면 움직여도 멈추지 않게 모든 범위 할당 /
         * (최대 창 기준) 창 바뀌면 좌표도 달라짐.
         */
        if (floorX >= startData || floorX <= 76) {
            if (startData == 78) startData -= 1;
            if (ballY == top) changeDirection = 1;
            if (ballX == leftWall) changeDirection = 2;
            if (ballX == RightWall) changeDirection = 3;
            if (ballY == floor) changeDirection = 4;
            if (changeDirection == 0) {
                shoot();
            } else if (changeDirection == 1) {
                changeAngle_Top();
            } else if (changeDirection == 2) {
                changeAngle_Left();
            } else if (changeDirection == 3) {
                changeAngle_Right();
            } else if (changeDirection == 4) {
                reset();
            }
        }
    }
    return 0;
}

void reset() {
    GotoXY(80, 30);
    printf("○");
    changeDirection = 0;
    startData = 78;
}

void showTitle() {
    char buf[100];
    FILE *fpr = fopen("wall", "r");

    while (!feof(fpr)) {
        fgets(buf, 100, fpr);
        printf("%s", buf);
    }
    fclose(fpr);
}

void shoot() {
    GotoXY(80, --ballY);
    printf("○");
    Sleep(50); //공이 빨리 사라지지 않게 하기 위함
    GotoXY(80, ballY);
    printf(" ");
}

void changeAngle_Top() {
    GotoXY(--ballX, ++ballY);
    printf("○");
    Sleep(50);
    GotoXY(ballX, ballY);
    printf(" ");
}

void changeAngle_Left() {
    GotoXY(++ballX, ++ballY);
    printf("○");
    Sleep(50);
    GotoXY(ballX, ballY);
    printf(" ");
}

void changeAngle_Right() {
    GotoXY(--ballX, ++ballY);
    printf("○");
    Sleep(50);
    GotoXY(ballX, ballY);
    printf(" ");
}

void systemSetting() {
    CONSOLE_CURSOR_INFO cursorInfo = {0,};
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void keyListener() {}

void GotoXY(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
