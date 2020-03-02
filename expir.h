#include<stdio.h>
#include<time.h>
void exdisp()
{
    FILE *fo,*fp;
    int fd,fm,fy,cd,cm,cy,unit,bno,td,tm,ty,c=0,i,j,temp,r,rc;
    int *p=(int)malloc(sizeof(int));
    char name[20];
    float price;
    time_t k;
    time(&k);
    struct tm *local=localtime(&k);
    cd=local->tm_mday;
    cm=local->tm_mon +1;
    cy=local->tm_year +1900;
    fo=fopen("medlist.txt","r");
    fp=fopen("medlist.txt","r");
    system("cls");
    gotoxy(50,0);
    printf("Welcome to Medical Store\n\n");
    gotoxy(10,3);
    printf("Expiring medicine prompt");
    gotoxy(10,4);
    printf("--------------------------");



    gotoxy(3,5);
    printf("|| Batch No");
    gotoxy(15,5);
    printf("|| Name of medicine");
    gotoxy(38,5);
    printf("|| Price per tab");
    gotoxy(55,5);
    printf("|| Expiry Date");
    gotoxy(70,5);
    printf("|| Units");
    gotoxy(80,5);
    printf("||Days left(approx)||");
    gotoxy(3,6);
    for(r=0;r<100;r++)
        printf("-");



rc=7;

    while(fscanf(fo,"%i %s %f %i %i %i %i",&bno,&name,&price,&fd,&fm,&fy,&unit)!=EOF)
    {
        td=fd-cd;
        tm=fm-cm;
        ty=fy-cy;
        //printf("%i %i %i",td,tm,ty);
        ty=ty*365;
        ty=ty+tm*30;
        ty=ty+td;
        p[c]=ty;
        //printf("\n------%i-----\n",ty);
        c++;
    }
 //fclose(fo);

    //sorting starts
    for(i=0;i<c;i++)
    {
        for(j=0;j<c;j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    //sorting end
        //for(i=0;i<c;i++)
        //printf("------??? %i",p[i]);
        r=0;
    while(c!=0)
    {
        fseek(fp,0,SEEK_SET);
   //printf("\n%i--",p[r]);
    while(fscanf(fp,"%i %s %f %i %i %i %i",&bno,&name,&price,&fd,&fm,&fy,&unit)!=EOF)
    {
        td=fd-cd;
        tm=fm-cm;
        ty=fy-cy;
        ty=ty*365;
        ty=ty+tm*30;
        ty=ty+td;
        //printf("\n%i+",ty);
        if(p[r]==ty)
        {
            //printf("%i %s %.2f %i %i %i %i %i\n",bno,name,price,fd,fm,fy,unit,ty);
            gotoxy(3,rc);
            printf("|| %i",bno);
            gotoxy(15,rc);
            printf("|| %s",name);
            gotoxy(38,rc);
            printf("|| %.2f",price);
            gotoxy(55,rc);
            printf("|| %i-%i-%i",fd,fm,fy);
            gotoxy(70,rc);
            printf("|| %i",unit);
            gotoxy(80,rc);
            if(ty<0)
               printf("|| %i (Expired) ",ty);
            else
            printf("|| %i",ty);
            rc++;
        }
        //r++;
    }
    //fclose(fp);
    c--;
    r++;
    }
    //fclose(fo);
    //fclose(fp);
   getch();
    //system("cls");
    main();
}
