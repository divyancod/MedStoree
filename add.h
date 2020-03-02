#include<stdio.h>
#include<stdlib.h>

void add()
{
    char name[20],madd;
    int option=1,num,bno,i,fd,fm,fy;
    int ex[8];
    float price;
    FILE *fh;
    while(option==1)
    {
    system("cls");
    fflush(stdin);
    gotoxy(50,0);
    printf("Welcome to Medical Store\n\n");

    //printing starts from here

    gotoxy(20,2);
    printf("New Medicine Addition Prompt");
    gotoxy(19,3);
    for(i=0;i<30;i++)
    {
        printf("-");
    }
    gotoxy(20,6);
    printf("Enter Batch Number : ");
    gotoxy(20,8);
    printf("Name of Medicine : ");
    gotoxy(20,10);
    printf("Price per tab : ");
    gotoxy(20,12);
    printf("Expiry date : ");
    gotoxy(20,14);
    printf("Total units : ");

    //scaning starts here

    gotoxy(45,6);
    //fflush(stdin);
    scanf("%i",&bno);
    gotoxy(45,8);
    fflush(stdin);
    scanf("%s",&name);
    fflush(stdin);
    gotoxy(45,10);
    scanf("%f",&price);
    gotoxy(45,12);
    ex[0]=(int)getch()-48;
    printf("%i",ex[0]);
    ex[1]=(int)getch()-48;
    printf("%i",ex[1]);
    gotoxy(47,12);
    printf("/");
    ex[2]=(int)getch()-48;
    printf("%i",ex[2]);
    ex[3]=(int)getch()-48;
    printf("%i",ex[3]);
    gotoxy(50,12);
    printf("/");
    for(i=4;i<=7;i++)
    {
        ex[i]=(int)getch()-48;
        printf("%i",ex[i]);
    }
    fd=ex[0]*10+ex[1];
    fm=ex[2]*10+ex[3];
    fy=2000+ex[6]*10+ex[7];
   // scanf("%s",&exp);
    gotoxy(45,14);
    scanf("%i",&num);
    fflush(stdin);
    //printf("%i %s %.2f %i %i %i %i",bno,name,price,fd,fm,fy,num);

    //after inputing data
    gotoxy(20,16);
    printf("Do you want to save this record?");
    gotoxy(20,18);
    printf("1.Re-Enter 2.Save 3.Exit without adding  ");
    scanf("%i",&option);
    fflush(stdin);
    if(option==2)
    {
    fh=fopen("medlist.txt","a");
    fprintf(fh,"%i %s %.2f %i %i %i %i\n",bno,name,price,fd,fm,fy,num);
    fclose(fh);
    gotoxy(20,20);
    printf("Medicine added Sucessfully :)");
    gotoxy(20,22);
    printf("Want to add more medicine [Y/N] : ");
    scanf("%c",&madd);
    option=1;
    if(madd=='n'||madd=='N')
        main();
    }
    else if(option==3)
    {
        main();
    }
    }
}

