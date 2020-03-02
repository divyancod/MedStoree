#include<stdio.h>
#include<time.h>

void dmp()
{
    int i;
    system("cls");
    gotoxy(50,0);
    printf("Welcome to Medical Store\n");
    gotoxy(20,2);
    printf("Sale by date \\ month prompt");
    gotoxy(19,3);
    for(i=0;i<30;i++)
    {
        printf("-");
    }

}
void tsale()
{
    FILE *f;
    int bno,quan,d,m,y,res2,resp,res3,i,fd,fm,fy;
    float price,tprice;
    char name[20],exp[14];
    //time start
    int cd,cm,cy;
    time_t k;
    time(&k);
    struct tm *local=localtime(&k);
    cd=local->tm_mday;
    cm=local->tm_mon +1;
    //time end

    f=fopen("medsale.txt","r");
    dmp();
    gotoxy(20,5);
    printf("1.Total sale by date");
    gotoxy(20,6);
    printf("2.Total sale by month");
    gotoxy(20,7);
    resp=(int)getch();




    if(resp==49)
    {
        notdate:
        //system("cls");
        dmp();
        gotoxy(20,5);
        printf("Please Enter Date \\ Press 0 for today sale : ");
        scanf("%i",&res2);
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
        if(res2==0)
        {
            while(fscanf(f,"%i %s %f %i %i %i %i %f %i %i %i",&bno,&name,&price,&fd,&fm,&fy,&quan,&tprice,&d,&m,&y)!=EOF)
            {
                gotoxy(20,7);
                if(cd==d)
                {
                gotoxy(5,i);
                printf("|| %i",bno);
                gotoxy(16,i);
                printf("|| %s",name);
                gotoxy(35,i);
                printf("|| %.2f",price);
                gotoxy(56,i);
                printf("|| %i-%i-%i",fd,fm,fy);
                gotoxy(68,i);
                printf("|| %i",quan);
                gotoxy(79,i);
                printf("|| %.2f",tprice);
                gotoxy(96,i);
                printf("|| %i-%i-%i\n",d,m,y);
                i++;

                //printf("%i %s %.2f %s %i %.2f %i %i %i\n",bno,name,price,exp,quan,tprice,d,m,y);
                }
            }
        }
        else if(res2<=31)
        {
            while(fscanf(f,"%i %s %f %i %i %i %i %f %i %i %i",&bno,&name,&price,&fd,&fm,&fy,&quan,&tprice,&d,&m,&y)!=EOF)
            {

                gotoxy(20,7);
                if(res2==d)
                {

                gotoxy(5,i);
                printf("|| %i",bno);
                gotoxy(16,i);
                printf("|| %s",name);
                gotoxy(35,i);
                printf("|| %.2f",price);
                gotoxy(56,i);
                printf("|| %i-%i-%i",fd,fm,fy);
                gotoxy(68,i);
                printf("|| %i",quan);
                gotoxy(79,i);
                printf("|| %.2f",tprice);
                gotoxy(96,i);
                printf("|| %i-%i-%i\n",d,m,y);
                i++;
                //printf("%i %s %.2f %s %i %.2f %i %i %i\n",bno,name,price,exp,quan,tprice,d,m,y);
                }
            }
        }
        else
        {
            system("cls");
            gotoxy(20,7);
            printf("Please Enter a valid date");
            getch();
            goto notdate;
        }

    }
    else if(resp == 50)
    {
        notmonth:
        system("cls");
        dmp();
        gotoxy(20,5);
        printf("Please Enter Month \\ Press 0 for today sale : ");
        scanf("%i",&res3);
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
        if(res3==0)
        {
            while(fscanf(f,"%i %s %f %i %i %i %i %f %i %i %i",&bno,&name,&price,&fd,&fm,&fy,&quan,&tprice,&d,&m,&y)!=EOF)
            {
                gotoxy(20,5);
                if(cm==m)
                {
                gotoxy(5,i);
                printf("|| %i",bno);
                gotoxy(16,i);
                printf("|| %s",name);
                gotoxy(35,i);
                printf("|| %.2f",price);
                gotoxy(56,i);
                printf("|| %i-%i-%i",fd,fm,fy);
                gotoxy(68,i);
                printf("|| %i",quan);
                gotoxy(79,i);
                printf("|| %.2f",tprice);
                gotoxy(96,i);
                printf("|| %i-%i-%i\n",d,m,y);
                i++;
                //printf("%i %s %.2f %s %i %.2f %i %i %i\n",bno,name,price,exp,quan,tprice,d,m,y);
                }
            }
        }
        else if(res3<=12)
        {
            while(fscanf(f,"%i %s %f %i %i %i %i %f %i %i %i",&bno,&name,&price,&fd,&fm,&fy,&quan,&tprice,&d,&m,&y)!=EOF)
            {
                gotoxy(20,5);
                if(res3==m)
                {
                gotoxy(5,i);
                printf("|| %i",bno);
                gotoxy(16,i);
                printf("|| %s",name);
                gotoxy(35,i);
                printf("|| %.2f",price);
                gotoxy(56,i);
                printf("|| %i-%i-%i",fd,fm,fy);
                gotoxy(68,i);
                printf("|| %i",quan);
                gotoxy(79,i);
                printf("|| %.2f",tprice);
                gotoxy(96,i);
                printf("|| %i-%i-%i\n",d,m,y);
                i++;
                //printf("%i %s %.2f %s %i %.2f %i %i %i\n",bno,name,price,exp,quan,tprice,d,m,y);
                }
            }
        }
        else
        {
            gotoxy(20,5);
            printf("Please enter a valid month");
            getch();
            goto notmonth;
        }
    }
    else
    {
        dmp();
        gotoxy(20,5);
        printf("Invalid response");
    }
    getch();
    fclose(f);
    main();
}

