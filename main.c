#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77

void GotoXY(int x, int y);
void keyListener(char buffer[]);

int main() {
    char buf[1000];

    FILE *fpr = fopen("moveFloor\\mainFloor", "r");

    int lineCount = 0;
    while (!feof(fpr)) {
        fgets(buf, 1000, fpr);
        printf("%s", buf);
        lineCount++;
        if (lineCount - 1 == 33) {
            lineCount -= 1;
            keyListener(buf);
        }
    }
    fclose(fpr);
    return 0;
}

void keyListener(char buffer[]) {
    char c;
    int x = 78;
    int y = 27;

    while (1) {
        if (_kbhit()) {
            c = _getch();
            if (c == -32) {
                c = _getch();
                if (x == 60 || x == 101) break;

                switch (c) {
                    case LEFT:
                        GotoXY(x - 1, y); printf("%s", buffer);
                        x -= 1;
                        break;
                    case RIGHT:
                        GotoXY(x + 1, y); printf("%s", buffer);
                        x += 1;
                        break;
                }
            }
        }
    }
}

void GotoXY(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
