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
void ballCreate();
void dropBricks();
void dropItem();

int floorX = 77;
int floorY = 31;

int ballX = 80;
int ballY = 30;

int bricksY = 1;

int changeDirection = 0;
int floorStartData = 78;
int ballStartData = 0;
int gameEndData = 0;

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

                //죽고 나서 바로 플레이 됨을 방지하기 위함
                if (gameEndData == 1) {
                    Sleep(1500);
                    gameEndData = 0;
                }

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

        //[첫 시작이 N ~ 78 , 76 ~ 0 ] 만약 조건문이 77일시 바로 공이 발사됨을 방지하기 위하여, 변수로 따로 지정.
        if (floorX >= floorStartData || floorX <= 76) {
            if (floorStartData == 78) floorStartData -= 1;
            if (ballStartData == 0) {
                if (ballY == top) changeDirection = 1;
                if (ballX == leftWall) changeDirection = 2;
                if (ballX == RightWall) changeDirection = 3;
                if (ballY == floor) changeDirection = 4;
            } else if (ballStartData == 1) {
                if (ballY == top) changeDirection = 1;
                if (ballX == leftWall) changeDirection = 5;
                if (ballX == RightWall) changeDirection = 7;
                if (ballY == floor) changeDirection = 4;
            } else if (ballStartData == 2) {
                if (ballY == top) changeDirection = 2;
                if (ballX == leftWall) changeDirection = 5;
                if (ballX == RightWall) changeDirection = 7;
                if (ballY == floor) changeDirection = 4;
            } else if (ballStartData == 3) {
                if (ballY == top) changeDirection = 3;
                if (ballX == leftWall) changeDirection = 5;
                if (ballX == RightWall) changeDirection = 7;
                if (ballY == floor) changeDirection = 4;
            }

            if (ballX == floorX && ballY == floorY || ballX == floorX + 1 && ballY == floorY) {
                dropBricks();
                changeDirection = 7; //발판 왼쪽 2개
                ballStartData = 1;
                ++bricksY;
            }

            if (ballX == floorX + 2 && ballY == floorY || ballX == floorX + 3 && ballY == floorY) {
                dropBricks();
                changeDirection = 6; //발판 가운데 2개
                ++bricksY;
            }

            if (ballX == floorX + 4 && ballY == floorY || ballX == floorX + 5 && ballY == floorY) {
                dropBricks();
                changeDirection = 5; //발판 오른쪽 2개
                ballStartData = 1;
                ++bricksY;
            }

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
                    ballStartData = 2;
                    break;
                case 6:
                    straight();
                    ballStartData = 0;
                    break;
                case 7:
                    changeAngle_LeftTop();
                    ballStartData = 3;
                    break;
                default:
                    break;
            }
        }
    }
}

void dropBricks() {
    GotoXY(60, bricksY);
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    //X60 벽 기준 바로 오른쪽
    //X94 벽 기준 바로 왼쪽
}

void dropItem() {
    /**
     * 블럭을 n번 부술 때마다 아이템이 드랍된다. (상의)
     * 밑 아이템 들의 드랍 [ 확률 ] , [ 사용 수 ] , [ 중첩 ]을 지정한다. (상의)
     * 1. 공이 넓은 범위로 블럭을 제거한다.
     * 2. 공이 1번 무적으로 변한다.
     * 3. n개의 벽을 제외하고 나머지 벽을 다 제거한다.
     * 4. 맨 아래의 벽을 모두 제거한다.
     * 5. 맨 밑 줄에있는 n개의 줄을 제거한다.
     * 6. 발판 조작이 빨라진다.
     */
}

void reset() {
    floorX = 77;
    floorY = 31;

    ballX = 80;
    ballY = 30;

    bricksY = 1;

    changeDirection = 0;
    floorStartData = 78;
    ballStartData = 0;
    gameEndData = 1;

    system("cls");
    showTitle();
}

void showTitle() {
    char buf[100];
    FILE *fpr = fopen("title", "r");

    while (!feof(fpr)) {
        fgets(buf, 100, fpr);
        printf("%s", buf);
    }
    fclose(fpr);
    //INFO
    GotoXY(110, 9);
    printf("━━━━━━━[ \033[35mBEST \033[0m]━━━━━━━");
    GotoXY(110, 10);
    printf("Record : ");
    GotoXY(110, 11);
    printf("Breaking Bricks : ");
    GotoXY(110, 12);
    printf(" ");
    GotoXY(110, 13);
    printf("━━━━━━━[ \033[36mPLAY \033[0m]━━━━━━━");
    GotoXY(110, 14);
    printf("Record : ");
    GotoXY(110, 15);
    printf("Breaking Bricks : ");
    GotoXY(110, 16);
    printf("Money : ");
    GotoXY(110, 17);
    printf("Time : ");
}

void shoot() {
    GotoXY(80, --ballY);
    printf("○");
    Sleep(50);
    GotoXY(80, ballY);
    printf(" ");
}

//가운데 2개 발판에 닿았을 때 직진한다.
void straight() {
    GotoXY(ballX, --ballY);
    ballCreate();
}

/**
 * 위로 부딪히면 왼쪽아래로 간다.
 * 수정 사항: 랜덤 값으로 오른쪽 왼쪽 방향 조절해야 함
 */
void changeAngle_Top() {
    GotoXY(--ballX, ++ballY);
    ballCreate();
}

//왼쪽으로 부딪히면 오른쪽 아래로 간다.
void changeAngle_Left() {
    GotoXY(++ballX, ++ballY);
    ballCreate();
}

//오른쪽으로 부딪히면 왼쪽 아래로 간다.
void changeAngle_Right() {
    GotoXY(--ballX, ++ballY);
    ballCreate();
}

//왼쪽 2개 발판에 닿았을 때 왼쪽 위로 간다.
void changeAngle_LeftTop() {
    GotoXY(--ballX, --ballY);
    ballCreate();
}

//오른쪽 2개 발판에 닿았을 때 오른쪽 위로 간다.
void changeAngle_RightTop() {
    GotoXY(++ballX, --ballY);
    ballCreate();
}

void ballCreate() {
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
