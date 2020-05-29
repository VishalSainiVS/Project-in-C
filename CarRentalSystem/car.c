#include"conio2.h"
#include<stdio.h>
#include<string.h>
#include"car.h"
#include<stdlib.h>
#include<time.h>
#include"style.h"
#include<math.h>
void addAdmin()
{
    FILE *f=fopen("admin.bin","rb");
    if(f==NULL)
    {
      FILE *f=fopen("admin.bin","wb");
      user u[2]={{"vishal","saini","vishal"},{"admin","abc","sanju"}};
      fwrite(&u,sizeof(u),1,f);
      fclose(f);
      gotoxy(48,17);
      printf("file saved sucessfully");
      _getch();
    }
    else
    {
        fclose(f);
    }

}
user* getInput()
{
        static user usr;
        fgets(usr.userid,20,stdin);
        char *pos;
        pos=strchr(usr.userid,'\n');
        *pos='\0';

        if(strcmp(usr.userid,"0")==0)
        {
          textcolor(LIGHTRED);
          gotoxy(50,21);
          printf("Login cancelled");
        gotoxy(42,23);
          textcolor(LIGHTGRAY);
          printf("Press any key to go previous menu.");
          _getch();
          return NULL;
        }
    gotoxy(48,16);
    textcolor(LIGHTCYAN);
    printf("Enter password : ");
    fflush(stdin);
    int i=0,j=48+17;
    textcolor(WHITE);
    for(;;)
    {
        usr.pwd[i]=_getch();
        if(usr.pwd[i]==13)
        {
            break;
        }
        else if(usr.pwd[i]=='\b'&&j>64)
        {
            if(j==65)
            {
            gotoxy(j,16);
            usr.pwd[i]='\0';
            i=0;
            }
            else
            {
            j=j-1;
            gotoxy(j,16);
            printf(" ");
            gotoxy(j,16);
            usr.pwd[i]='\0';
            i--;
            }
        }
        else
        {
            if(i<=18)
            {
        printf("*");
        i++;
        j++;
            }
            else
            {
               usr.pwd[i]='\0';
            }
        }
    }
    usr.pwd[i]='\0';
    if (strcmp(usr.pwd,"0")==0)
    {
        textcolor(LIGHTRED);
          gotoxy(48,21);
          printf("Login cancelled");
          gotoxy(42,23);
          textcolor(LIGHTGRAY);
          printf("Press any key to go previous menu.");
          _getch();
          return NULL;
    }
    return &usr;
}
int checkUserExist(user u,char *usertype)
{
    if(strcmp(u.userid,"")==0|| strcmp(u.pwd,"")==0)
    {

        gotoxy(46,21);
        textcolor(LIGHTRED);
        printf("BOTH FILEDS ARE MANDATORY");
        gotoxy(46,23);
          textcolor(LIGHTGRAY);
          printf("Press any key to re-enter.");
        _getch();
        gotoxy(46,21);
        printf("\t\t\t\t\t\t\t");
        return 0;
    }
    int found=0;
    if(!(strcmp(usertype,"admin")))
    {
        FILE *fp=fopen("admin.bin","rb");
        user users;
        while(fread(&users,sizeof(users),1,fp)==1)
        {
            if(strcmp(u.userid,users.userid)==0&&strcmp(u.pwd,users.pwd)==0)
            {
                found=1;
                break;
            }
        }
        if(!found)
        {
            gotoxy(46,21);
            textcolor(LIGHTRED);
            printf("INVALID USERID OR PASSWORD");
            gotoxy(46,23);
          textcolor(LIGHTGRAY);
          printf("Press any key to re-enter.");
            _getch();
            fclose(fp);
            return 0;
        }
        fclose(fp);
        return 1;
    }

        if(!(strcmp(usertype,"emp")))
    {
        FILE *fp=fopen("emp.bin","rb");
        user users;
        while(fread(&users,sizeof(users),1,fp)==1)
        {
            if(strcmp(u.userid,users.userid)==0&& strcmp(u.pwd,users.pwd)==0)
            {
                found=1;
                break;
            }
        }
        if(!found)
        {
            gotoxy(46,21);
            textcolor(LIGHTRED);
            printf("INVALID USERID OR PASSWORD");
            _getch();
            fclose(fp);
            return 0;
        }
        fclose(fp);
        return 1;
    }
    return 0;
}

void addEmployee()
{
    FILE *f=fopen("emp.bin","rb");
    int id,h;
    char empid[10],emp[10]={"Emp-"},uchoice;
    user u,ur;
    if(f==NULL)
    {
        f=fopen("emp.bin","ab");
        id=1;
        sprintf(empid,"%d",id);
        strcat(emp,empid);
        strcpy(u.userid,emp);
        strcpy(emp,"Emp-");

    }
    else
    {
        do
        {
        f=fopen("emp.bin","ab+");
        fseek(f,-60,SEEK_END);
        fread(&ur,sizeof(user),1,f);
        char sub[4],str[20];
        strcpy(str,ur.userid);
        sub_str(str,sub,'-');
        id=atoi(sub);
        id++;
        sprintf(empid,"%d",id);
        strcat(emp,empid);
        strcpy(u.userid,emp);
        strcpy(emp,"Emp-");


        clrscr();
        addEmployeeStyle();

        int i;
        do
        {
        gotoxy(3,10);
        textcolor(YELLOW);
        printf("Enter Employee Name: ");
        fflush(stdin);
        fgets(u.name,sizeof(u.name),stdin);
        char *pos;
        pos=strchr(u.name,'\n');
        *pos='\0';
         h=13;
        i=checkBlankInput(u.name,h);
        gotoxy(22,11);
        printf("\t\t\t");

    }while(i==0);

         do
        {
            i=0;
        gotoxy(3,11);
        textcolor(YELLOW);
        printf("Enter Employee Password: ");
        fflush(stdin);
        fgets(u.pwd,sizeof(u.pwd),stdin);
        char *pos;
        pos=strchr(u.pwd,'\n');
        *pos='\0';
        while(u.pwd[i]!='\0')
        {
            i++;
        }
        i--;
        if(i<4)
        {
        gotoxy(3,13);
        textcolor(LIGHTRED);
        printf("Password atleast have 5 characters");
        gotoxy(3,15);
        textcolor(WHITE);
        printf("Press any key to re-enter.");
        _getch();
        gotoxy(3,13);
        printf("\t\t\t\t\t\t");
        gotoxy(3,15);
        printf("\t\t\t\t\t\t");
        gotoxy(22,11);
        printf("\t\t\t");
        }
    }while(i<4);

        fseek(f,0,SEEK_END);
        fwrite(&u,sizeof(user),1,f);
        gotoxy(3,13);
        textcolor(LIGHTGREEN);
        printf("Employee Added Successfully. ");
        printf("Employee id is: %s",u.userid);
        gotoxy(3,15);
        textcolor(WHITE);
        fclose(f);

        printf("Do you want to add More Y/N : ");
        fflush(stdin);
        scanf("%c",&uchoice);
        id++;
        sprintf(empid,"%d",id);
        strcat(emp,empid);
        strcpy(u.userid,emp);
        strcpy(emp,"Emp-");
        }while(uchoice=='Y'|| uchoice=='y');
    }
}
void sub_str(char *str,char *sub,char c)
{
    int i,j=0,f=0;
    for(i=0;str[i]!=c;i++)
    {
        f++;
    }
    f++;
    for(i=f;str[i]!='\0';i++)
    {
        sub[j]=str[i];
        j++;
    }
    sub[j]='\0';
}


void addCarDetails()
{
    FILE *f=fopen("car.bin","rb");
    int id,h,g;
    char uchoice;
    car c,cr;
    if(f==NULL)
    {
        f=fopen("car.bin","ab+");
        id=1;
    }
    else
    {


        f=fopen("car.bin","rb");
        fseek(f,-(sizeof(car)),SEEK_END);
        fread(&cr,sizeof(car),1,f);
        id=cr.carid;
        id++;
        fclose(f);
    }
    do
    {

        clrscr();
        addCarDetailsStyle();
        c.carid=id;
        int i;
        do
        {
        gotoxy(3,10);
        textcolor(YELLOW);
        printf("Enter Car Name: ");
        fflush(stdin);

        fgets(c.carName,sizeof(c.carName),stdin);
        char *pos;
        pos=strchr(c.carName,'\n');
        *pos='\0';
         h=12;

        i=checkBlankInput(c.carName,h);
        gotoxy(3,15);
        printf("\t\t\t");
        }while(i==0);

        i=0;
        do
        {

        gotoxy(3,11);
        textcolor(YELLOW);
        printf("Enter Car Capacity: ");
        fflush(stdin);
         g=11;
         h=21;
        c.capacity=onlyIntegerInput(h,g);
        if(c.capacity==0)
        {
        gotoxy(3,13);
        textcolor(LIGHTRED);
        printf("capacity can not be 0 ");
        gotoxy(3,15);
        textcolor(WHITE);
        printf("Press any key to re-enter.");
        _getch();
        gotoxy(3,13);
        printf("\t\t\t\t\t\t");
        gotoxy(23,11);
        printf("\t\t\t");
        }

        }while(c.capacity==0);

        gotoxy(3,12);
        printf("Enter Number Of Cars: ");
         g=12;
         h=23;
        c.carCount=onlyIntegerInput(h,g);
        gotoxy(3,13);
        printf("Enter Car Price: ");
        g=13;
        h=18;
        c.price=onlyIntegerInput(h,g);

        f=fopen("car.bin","ab");
        fwrite(&c,sizeof(car),1,f);
        gotoxy(3,15);
        textcolor(LIGHTGREEN);
        printf("Car Added Successfully. ");
        printf("Car id is: %d",c.carid);
        gotoxy(3,17);
        textcolor(WHITE);
        fclose(f);
        printf("Do you want to add More Y/N : ");
        fflush(stdin);
        scanf("%c",&uchoice);
        id++;
        }while(uchoice=='Y'|| uchoice=='y');

}

void viewEmployee()
{
    FILE *f=fopen("emp.bin","rb");
    user u;
    int y=13;
    if(f==NULL)
    {
        gotoxy(1,y);
        printf("no data found.");
    }

    while(fread(&u,sizeof(user),1,f)==1)
    {
        gotoxy(2,y);
        printf("%s",u.userid);
        gotoxy(22,y);
        printf("%s",u.name);
        gotoxy(42,y);
        printf("%s",u.pwd);
        y++;
    }
    gotoxy(1,y+3);
    textcolor(WHITE);
    printf("Press any key to go previous window.");
    fclose(f);
    _getch();
}


void showCarDetails()
{
    FILE *f=fopen("car.bin","rb");
    car c;
    int y=13;

    while(fread(&c,sizeof(car),1,f)==1)
    {
        gotoxy(2,y);
        printf("%d",c.carid);
        gotoxy(20,y);
        printf("%s",c.carName);
        gotoxy(43,y);
        printf("%d",c.capacity);
        gotoxy(65,y);
        printf("%d",c.carCount);
        gotoxy(83,y);
        printf("%d",c.price);
        y++;

    }
    gotoxy(1,y+3);
    textcolor(WHITE);
    printf("Press any key to go previous window.");
     fclose(f);
    _getch();
}
void deleteEmployee()
{
    FILE *f1=fopen("emp.bin","rb");
    int found=0;
    user u;
    char str[20];
    if(f1==NULL)
    {
        gotoxy(5,13);
        textcolor(LIGHTRED);
        printf("Data not present.");
    }
    FILE *f2=fopen("temp.bin","wb+");
    gotoxy(5,11);
    textcolor(WHITE);
    printf("Enter the Emplyee ID : ");
    fflush(stdin);
    scanf("%s",str);
    while(fread(&u,sizeof(user),1,f1)==1)
    {
        if(strcmp(u.userid,str)!=0)
        {
            fwrite(&u,sizeof(user),1,f2);
        }
        else
        {
            found=1;
        }
    }
    fclose(f1);
    rewind(f2);
    if(found==1)
    {
        f1=fopen("emp.bin","wb");
        while(fread(&u,sizeof(user),1,f2)==1)
        {
            fwrite(&u,sizeof(user),1,f1);
        }
        gotoxy(5,13);
        textcolor(LIGHTGREEN);
        printf("File Deleted Successfully.");
    }
    else
    {
        gotoxy(5,13);
        textcolor(LIGHTRED);
        printf("wrong input ID.");
    }
    fclose(f1);
    remove("temp.bin");

}

void deleteCarDetails()
{
    FILE *f1=fopen("car.bin","rb");
    int found=0;
    car u;
    int str;
    if(f1==NULL)
    {
        gotoxy(5,13);
        textcolor(LIGHTRED);
        printf("Data not present.");
    }
    FILE *f2=fopen("temp.bin","wb+");
    gotoxy(5,11);
    textcolor(WHITE);
    printf("Enter the Car ID : ");
    fflush(stdin);
    scanf("%d",&str);
    while(fread(&u,sizeof(car),1,f1)==1)
    {
        if(u.carid!=str)
        {
            fwrite(&u,sizeof(car),1,f2);
        }
        else
        {
            found=1;
        }
    }
    fclose(f1);
    rewind(f2);
    if(found==1)
    {
        f1=fopen("car.bin","wb");
        while(fread(&u,sizeof(car),1,f2)==1)
        {
            fwrite(&u,sizeof(car),1,f1);
        }
        gotoxy(5,13);
        textcolor(LIGHTGREEN);
        printf("File Deleted Successfully.");
    }
    else
    {
        gotoxy(5,13);
        textcolor(LIGHTRED);
        printf("wrong input ID.");
    }
    fclose(f1);
    remove("temp.bin");
}
void switchDefault()
{
    gotoxy(52,22);
    textcolor(RED);
    printf("INVALID INPUT");
    gotoxy(48,24);
    textcolor(WHITE);
    printf("Press any key to re-enter");
    _getch();
}

int availableCars()
{
    FILE *f;
    car c;
    int y=13;
        clrscr();
        rentCarStyle();
    fflush(stdin);
    f=fopen("car.bin","rb");
    while(fread(&c,sizeof(car),1,f)==1)
    {
        if(c.carCount!=0)
        {
                textcolor(GREEN);
                 gotoxy(2,y);
                printf("%d",c.carid);
                gotoxy(20,y);
                printf("%s",c.carName);
                gotoxy(43,y);
                printf("%d",c.capacity);
                gotoxy(65,y);
                printf("%d",c.carCount);
                gotoxy(83,y);
                printf("%d",c.price);
                y++;
        }

    }
    fclose(f);
return y;
}
int unavailableCars( int a)
{
    FILE *f=fopen("car.bin","rb");
    car c;
    int y=a;
     gotoxy(48,y);
    textcolor(RED);
    printf("UN-AVAILABLE CARS");
    y=y+2;
    f=fopen("car.bin","rb");
    while(fread(&c,sizeof(car),1,f)==1)
    {
        if(c.carCount==0)
        {
        gotoxy(2,y);
        printf("%d",c.carid);
        gotoxy(20,y);
        printf("%s",c.carName);
        gotoxy(43,y);
        printf("%d",c.capacity);
        gotoxy(65,y);
        printf("%d",c.carCount);
        gotoxy(83,y);
        printf("%d",c.price);
        y++;
        }
    }
    fclose(f);
    return y;
}
void rentCar(int a)
{
    int y=a,d;
    car c;
    cust cr;
    char str[30];
    FILE *f,*g;
    int i;
    do
    {
        i=0;
    gotoxy(1,++y);
    textcolor(WHITE);
    printf("Enter car id to grab : ");
    scanf("%d",&d);

    f=fopen("car.bin","rb+");

    while(fread(&c,sizeof(car),1,f)==1)
    {
        if(c.carid==d&&c.carCount!=0)
        {

            c.carCount--;
            strcpy(str,c.carName);
            fseek(f,-(sizeof(car)),SEEK_CUR);
            fwrite(&c,sizeof(car),1,f);
            i++;
            break;
        }
    }
    fclose(f);
    if(i==0)
    {
        y=y+2;
        gotoxy(1,y);
        textcolor(LIGHTRED);
        printf("INVALID ID");
        gotoxy(1,++y);
        textcolor(WHITE);

        printf("Press any to re-enter");
        fflush(stdin);
        _getch();
        y=y-3;
        gotoxy(1,y);
        printf("\t\t\t\n\t\t\t\n\t\t\t\n\t\t\t");
        y=y-1;


    }
    }while(i==0);

    strcpy(cr.carname,str);

    gotoxy(1,++y);
    textcolor(LIGHTGREEN);
    printf("Enter Customer Name: ");
    fflush(stdin);
        fgets(cr.custName,sizeof(cr.custName),stdin);
        char *pos;
        pos=strchr(cr.custName,'\n');
        *pos='\0';

    gotoxy(1,++y);
    textcolor(WHITE);
    printf("Enter Pickup location: ");

    fflush(stdin);
        fgets(cr.pick,sizeof(cr.pick),stdin);
        pos=strchr(cr.pick,'\n');
        *pos='\0';

    gotoxy(1,++y);
    textcolor(LIGHTGREEN);
    printf("Enter drop location: ");
    fflush(stdin);
        fgets(cr.drop,sizeof(cr.drop),stdin);

        pos=strchr(cr.drop,'\n');
        *pos='\0';

    gotoxy(1,++y);
    textcolor(WHITE);
    printf("Enter Starting date DD/MM/YY: ");
    do
    {
        fflush(stdin);
    scanf("%d/%d/%d",&cr.sd.tm_mday,&cr.sd.tm_mon,&cr.sd.tm_year);
    int datevalid= isValidDate(cr.sd);
    if(datevalid==1)
        break;
    else
    {
        gotoxy(1,++y);
    textcolor(RED);
    printf("WRONG DATE");
    _getch();
    --y;
     gotoxy(1,++y);
    printf("\t\t\t\t");
    gotoxy(31,--y);
    printf("\t\t\t\t");
    gotoxy(31,y);
    }
    }while(1);

    gotoxy(1,++y);
    textcolor(WHITE);
    printf("Enter Ending date DD/MM/YY: ");
    do
    {
        fflush(stdin);
    scanf("%d/%d/%d",&cr.ed.tm_mday,&cr.ed.tm_mon,&cr.ed.tm_year);
    int datevalid=isValidDate(cr.ed);
    if( datevalid==1)
        break;
    else
    {
        gotoxy(1,++y);
    textcolor(RED);
    printf("WRONG DATE");
    _getch();
    --y;
    gotoxy(1,++y);
    printf("\t\t\t\t");
    gotoxy(29,--y);
    printf("\t\t\t\t");
    gotoxy(29,y);

    }
    }while(1);
    g=fopen("carRent.bin","ab");
    if(g==NULL)
    {
        g=fopen("carRent.bin","wb");
        fwrite(&cr,sizeof(cr),1,g);
    }
    else
    {
    fwrite(&cr,sizeof(cr),1,g);
    }
    fclose(g);
    gotoxy(1,++y);
    textcolor(LIGHTGREEN);
    printf("File saved successfully");
    _getch();
}


int isValidDate(struct tm dt)
{
    if(dt.tm_year>=2020&&dt.tm_year<=2022)
    {
        if(dt.tm_mon>=1&&dt.tm_mon<=12)
        {
            if(dt.tm_mday>=1&&dt.tm_mday<=31&&(dt.tm_mon==1||dt.tm_mon==3||dt.tm_mon==5||dt.tm_mon==7||dt.tm_mon==8||dt.tm_mon==10||dt.tm_mon==12))
                return 1;
            else if(dt.tm_mday>=1&&dt.tm_mday<=30&&(dt.tm_mon==2||dt.tm_mon==4||dt.tm_mon==6||dt.tm_mon==9||dt.tm_mon==11))
                    return 1;
            else if(dt.tm_mday>=1&&dt.tm_mday<=28)
                return 1;
            else if((dt.tm_mday==29&&dt.tm_mon==2)&&(dt.tm_year%400==0||(dt.tm_year%4==0&&dt.tm_year%100!=0)))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}

void bookingDetails()
{
    FILE *f;
    cust c;
    int y=11;
    f=fopen("carRent.bin","rb");
    while(fread(&c,sizeof(cust),1,f)==1)
    {

                textcolor(GREEN);
                 gotoxy(2,y);
                printf("%s",c.carname);
                gotoxy(15,y);
                printf("%s",c.custName);
                gotoxy(31,y);
                printf("%s",c.pick);
                gotoxy(45,y);
                printf("%s",c.drop);
                gotoxy(59,y);
                printf("%d-%d-%d",c.sd.tm_mday,c.sd.tm_mon,c.sd.tm_year);
                gotoxy(73,y);
                printf("%d-%d-%d",c.ed.tm_mday,c.sd.tm_mon,c.sd.tm_year);
                y++;

    }
    fclose(f);
}

int checkBlankInput(char *ur,int a)
{
    int i=0;
    while(ur[i]!='\0')
        {
            i++;
        }
        if(i==0)
        {
        gotoxy(3,a);
        textcolor(LIGHTRED);
        printf("Employee name should have atleast one character.");
        a=a+2;
        gotoxy(3,a);
        textcolor(WHITE);
        printf("Press any key to re-enter.");
        _getch();
        a=a-2;
        gotoxy(3,a);
        printf("\t\t\t\t\t\t\t");
        a=a+2;
        gotoxy(3,a);
        printf("\t\t\t\t\t\t");
        return 0;
        }
        else
            return 1;
}

int onlyIntegerInput(int f,int g)
{
    int ch,num=0,d,b=f;
    b=b+3;
    f=f+3;
    do
    {
        ch=_getch();
        if(ch>=48&&ch<=57)
        {
            d=ch-48;
            printf("%c",ch);
            num=num*10+(ch-48);
            f++;
        }
        else if(ch=='\b'&& f>=b)
        {   f--;
            num=(num-d)/10;
            gotoxy(f,g);
            printf("\t\t\t");
            gotoxy(f,g);
        }
        else if(ch==13)
        {
            break;
        }
    }while(1);

    return num;
}




