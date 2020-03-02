#include<stdio.h>
#include<conio.h>
void srecord()
{
    FILE *fsr;
    int bno,unit,d,m,y,fd,fm,fy,i;
    char name[20];
    float price,tprice;
    fsr=fopen("medsale.txt","r");

        system("cls");
        gotoxy(50,0);
        printf("Welcome to Medical Store\n");
        gotoxy(5,2);
        printf("|| Batch No");
        gotoxy(16,2);
        printf("|| Medicine Name");
        gotoxy(36,2);
        printf("|| Price per tab");
        gotoxy(56,2);
        printf("|| Expiry");
        gotoxy(68,2);
        printf("|| Quantity");
        gotoxy(79,2);
        printf("||Total price");
        gotoxy(96,2);
        printf("|| Sale Date ||");
        gotoxy(5,3);
        for(i=1;i<=105;i++)
        {
            printf("-");
        }

i=4;


    while(fscanf(fsr,"%i %s %f %i %i %i %i %f %i %i %i",&bno,name,&price,&fd,&fm,&fy,&unit,&tprice,&d,&m,&y)!=EOF)
    {
        //printf("%i %s %.2f %i-%i-%i %i %.2f %i-%i-%i\n",bno,name,price,fd,fm,fy,unit,tprice,d,m,y);
                gotoxy(5,i);
                printf("|| %i",bno);
                gotoxy(16,i);
                printf("|| %s",name);
                gotoxy(35,i);
                printf("|| %.2f",price);
                gotoxy(56,i);
                printf("|| %i-%i-%i",fd,fm,fy);
                gotoxy(68,i);
                printf("|| %i",unit);
                gotoxy(79,i);
                printf("|| %.2f",tprice);
                gotoxy(96,i);
                printf("|| %i-%i-%i\n",d,m,y);
                i++;
    }
    fclose(fsr);
    getch();
    main();
}
