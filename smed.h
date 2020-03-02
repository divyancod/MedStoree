#include<stdio.h>
#include<conio.h>
void disp()
{
    FILE *fh;
    char name[20];
    int unit,colm=8,i,bno,fd,fm,fy;
    float price;
    system("cls");
    fflush(stdin);
    fh=fopen("medlist.txt","r");
    gotoxy(50,0);
    printf("Welcome to Medical Store");
    gotoxy(50,3);
    printf("Medicine Record");
    gotoxy(5,5);
    printf("|| Batch No");
    gotoxy(20,5);
    printf("|| Name of medicine");
    gotoxy(42,5);
    printf("|| Price per tab");
    gotoxy(70,5);
    printf("|| Expiry Date");
    gotoxy(90,5);
    printf("|| Units received\n");
    gotoxy(5,6);
    for(i=5;i<108;i++)
    {
        printf("-");
    }

    while(fscanf(fh,"%i %s %f %i %i %i %i",&bno,&name,&price,&fd,&fm,&fy,&unit)!=EOF)
    {
        gotoxy(5,colm);
        printf("|| %i",bno);
        gotoxy(20,colm);
        printf("|| %s",name);
        gotoxy(42,colm);
        printf("|| %.2f",price);
        gotoxy(70,colm);
        printf("|| %i-%i-%i",fd,fm,fy);
        gotoxy(90,colm);
        printf("|| %i",unit);
        colm=colm+1;
        //printf("\n%s %.2f %s %s %i",name,price,manu,exp,unit);
    }
    fclose(fh);
    getch();
    main();
}

