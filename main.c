#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77

#define top 1
#define leftWall 60
#define RightWall 99
#define floor 31

void GotoXY(int x, int y);
void shoot();
void changeAngle_Top();
void changeAngle_Left();
void changeAngle_Right();
void changeAngle_LeftTop();
void changeAngle_RightTop();
void straight();
void systemSetting();
void showTitle();
void reset();

int floorX = 77;
int floorY = 31;

int ballX = 80;
int ballY = 30;

int changeDirection = 0;
int startData = 78;
int ballStartData = 0;

int main() {
    systemSetting();
    //첫 시작 파일 깨짐을 위해 불러온 뒤 클리어 후 다시 불러옴
    showTitle();
    system("cls");
    showTitle();

    char c;
    while (1) {
        if (_kbhit()) {
            c = _getch();
            if (c == -32) {
                c = _getch();
                //발판이 벽에 닿으면
                if (floorX == 60) {
                    floorX = 61;
                } else if (floorX == 95) {
                    floorX = 94;
                }
                //keyListener
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
            if (ballStartData == 0) {
                if (ballY == top) changeDirection = 1;
                if (ballX == leftWall) changeDirection = 2;
                if (ballX == RightWall) changeDirection = 3;
                if (ballY == floor) changeDirection = 4;
            } else {
                if (ballY == top) changeDirection = 1;
                if (ballX == leftWall) changeDirection = 5;
                if (ballX == RightWall) changeDirection = 7;
                if (ballY == floor) changeDirection = 4;
            }

            if (ballX == floorX && ballY == floorY || ballX == floorX + 1 && ballY == floorY) changeDirection = 7; //왼쪽 2개
            if (ballX == floorX + 2 && ballY == floorY || ballX == floorX + 3 && ballY == floorY) changeDirection = 6; //가운데 2개
            if (ballX == floorX + 4 && ballY == floorY || ballX == floorX + 5 && ballY == floorY) changeDirection = 5; //오른쪽 2개

            switch (changeDirection) {
                case 0:
                    shoot();
                    ballStartData = 0;
                    break;
                case 1:
                    changeAngle_Top();
                    ballStartData = 0;
                    break;
                case 2:
                    changeAngle_Left();
                    ballStartData = 0;
                    break;
                case 3:
                    changeAngle_Right();
                    ballStartData = 0;
                    break;
                case 4:
                    reset();
                    break;
                case 5:
                    changeAngle_RightTop();
                    ballStartData = 1;
                    break;
                case 6:
                    straight();
                    ballStartData = 0;
                    break;
                case 7:
                    changeAngle_LeftTop();
                    ballStartData = 1;
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}

void reset() {
    floorX = 77;
    floorY = 31;

    ballX = 80;
    ballY = 30;

    changeDirection = 0;
    startData = 78;
    ballStartData = 0;

    system("cls");
    showTitle();
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

void straight() {
    GotoXY(ballX, --ballY);
    printf("○");
    Sleep(50);
    GotoXY(ballX, ballY);
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

void changeAngle_LeftTop() {
    GotoXY(--ballX, --ballY);
    printf("○");
    Sleep(50);
    GotoXY(ballX, ballY);
    printf(" ");
}

void changeAngle_RightTop() {
    GotoXY(++ballX, --ballY);
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

void GotoXY(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
