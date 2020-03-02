#include<stdio.h>
#include<conio.h>
#include<time.h>
void rsale()
{
    char nam[20],cnf,exp[14],senam[20];
    float price,tprice;
    int quan,option=1,unit,bno,bn,coun=0,i,response,fd,fm,fy;
    FILE *fh,*fs;
    //time start
    int d,m,y;
    time_t k;
    time(&k);
    struct tm *local=localtime(&k);
    d=local->tm_mday;
    m=local->tm_mon +1;
    y=local->tm_year +1900;
    //time end
    system("cls");
    gotoxy(50,0);
    printf("Welcome to Medical Store");
    gotoxy(20,2);
    printf("Medicine sale prompt");
    gotoxy(19,3);
    for(i=0;i<36;i++)
    {
        printf("-");
    }
    gotoxy(20,4);
    printf("Please select the option [1/2] ");
    gotoxy(20,5);
    for(i=0;i<30;i++)
        printf("-");
    gotoxy(20,6);
    printf("1.Sale Medicine by name");
    gotoxy(20,7);
    printf("2.Sale Medicine by batch no");
    gotoxy(20,8);
    printf("0.Main menu");
    response=(int)getch();
    system("cls");
    while(option)
    {
    price=0,tprice=0;
    fh=fopen("medlist.txt","r");
    system("cls");
    gotoxy(50,0);
    printf("Welcome to Medical Store");
    gotoxy(20,2);
    printf("Medicine sale prompt");
    gotoxy(19,3);
    for(i=0;i<36;i++)
    {
        printf("-");
    }
    gotoxy(20,5);
    printf("Enter Batch no. : ");
    gotoxy(20,7);
    printf("Name of Medicine : ");
    gotoxy(20,9);
    printf("Price per tab: ");
    gotoxy(20,11);
    printf("Enter Quantity : ");
    gotoxy(20,13);
    printf("Enter expiry date: ");
    gotoxy(20,15);
    printf("Total price : ");


    if(response==49)
       {
           gotoxy(45,7);
           scanf("%s",&senam);
           while(fscanf(fh,"%i %s %f %i %i %i %i",&bn,&nam,&price,&fd,&fm,&fy,&unit)!=EOF)
           {
               if(strcmp(strupr(senam),strupr(nam)))
               {

               }
               else
               {
                   gotoxy(45,5);
                   printf("%i",bn);
                    gotoxy(45,9);
                    printf("%.2f",price);
                    gotoxy(45,13);
                    printf("%i-%i-%i",fd,fm,fy);
                    coun++;
                    break;
               }
           }
           if(coun==0)
           {
               gotoxy(45,5);
               scanf("%i",&bno);
                price=0;
                gotoxy(45,9);
                scanf("%f",&price);
                gotoxy(45,11);
                scanf("%i",&quan);
                tprice=price*quan;
                gotoxy(45,15);
                printf("%.2f",tprice);
                gotoxy(45,13);
                scanf("%s",&exp);
           }
           else{
            gotoxy(45,11);
            scanf("%i",&quan);
            tprice=price*quan;
            gotoxy(45,15);
            printf("%.2f",tprice);
            getch();
            coun=0;
            fclose(fh);
           }
       }





    else if(response==50)
    {
    gotoxy(45,5);
    scanf("%i",&bno);
    while(fscanf(fh,"%i %s %f %i %i %i %i",&bn,&nam,&price,&fd,&fm,&fy,&unit)!=EOF)
    {
        if(bn==bno)
        {
            //printf("%i %s %f %s %i",bn,nam,price,exp,unit);
            gotoxy(45,7);
            printf("%s",nam);
            gotoxy(45,9);
            printf("%.2f",price);
            gotoxy(45,13);
            printf("%i-%i-%i",fd,fm,fy);
            coun++;
            break;
        }
    }
    if(coun==0)
    {
        gotoxy(45,7);
        scanf("%s",&nam);
        price=0;
        gotoxy(45,9);
        scanf("%f",&price);
        gotoxy(45,11);
        scanf("%i",&quan);
        tprice=price*quan;
        gotoxy(45,15);
        printf("%.2f",tprice);
        gotoxy(45,13);
        scanf("%s",&exp);

    }
    else
    {
    gotoxy(45,11);
    scanf("%i",&quan);
    tprice=quan*price;
    gotoxy(45,15);
    printf("%.2f",tprice);
    getch();
    gotoxy(20,14);
    coun=0;
    fclose(fh);
    }

    }
    else if(response==48)
    {
        main();
    }
    else
    {
        system("cls");
        gotoxy(20,7);
        printf("Oops that was an invalid option (Try[1/2/0])");
        getch();
        rsale();
    }
    gotoxy(20,18);
    fflush(stdin);
    printf("Do you want to record this sale[Y/N] : ");
    scanf("%c",&cnf);
    if(cnf=='y'||cnf=='Y')
    {
        //do here coding stuff

        fs=fopen("medsale.txt","a");
        fprintf(fs,"%i %s %.2f %i %i %i %i %.2f %i %i %i\n",bn,nam,price,fd,fm,fy,quan,tprice,d,m,y);
        fclose(fs);
        gotoxy(20,20);
        printf("Sale recorded sucessfully ");
        getch();
        main();
    }
    else
    {
        gotoxy(20,20);
        printf("Sale recording aborted ");
        getch();
        main();
    }
    getch();
    }

}
