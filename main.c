#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funcs.h"
#include "add.h"
#include "smed.h"
#include "sale.h"
#include "srec.h"
#include"tsale.h"
#include"expir.h"
#include"exi.h"

int main()
{
    int response;
    system("cls");
    gotoxy(50,0);
    printf("Welcome to Medical Store\n\n");
    gotoxy(30,2);
    printf("Please select operation to perform");
    gotoxy(30,3);
    printf("-----------------------------------");
    gotoxy(30,5);
    fflush(stdin);
    printf("1.Add a new Medicine\n");
    gotoxy(30,6);
    printf("2.Record a sale\n");
    gotoxy(30,7);
    printf("3.Total Stock \n");
    gotoxy(30,8);
    printf("4.Total Sale Record (Month and Day) \n");
    gotoxy(30,9);
    printf("5.Sale Record by Month and Day");
    gotoxy(30,10);
    printf("6.Expiring medicines ");
    gotoxy(30,11);
    printf("7.Exit");
    response=(int)getch();
    //scanf("%i",&respone);
    if(response==49)add();
    else if(response==50) rsale();
    else if(response==51) disp();
    else if(response==52) srecord();
    else if(response==53) tsale();
    else if(response==54) exdisp();
    else if(response==55) mexit();
    else
    {
        gotoxy(30,14);
        printf("\a [Oops that was an invalid option]");
        getch();
        main();
    }

    return 0;
}
