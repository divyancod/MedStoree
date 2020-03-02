#include <windows.h>
#include<conio.h>

COORD coor={0,0};

    void gotoxy(int a,int b)
    {
        coor.X=a;
        coor.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coor);
    }


