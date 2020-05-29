#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include<string.h>
#include"car.h"
#include"style.h"

int main()
{
    frontpg();
    addAdmin();
    while(1)
    {
        page2();
        user *usr;
        int choice,type,a,b;
        char ch;
        do
        {
            type=12;
            //scanf("%d",&type);
            fflush(stdin);
            int s=_getch();
            if(s!=13)
            {
            printf("%d",s-48);
            }
            fflush(stdin);
            if (_getch()==13)
            {
                type= s-48;
            }

            int k=0;

            if(type==1)
            {
                do
                {
                    loginPanelStyle(1);
                    usr=getInput();
                    if(usr!=NULL)
                    {
                        k=checkUserExist(*usr,"admin");
                    }
                    else
                    {
                        break;
                    }

                }while(k==0);
                if(k==1)
                {
                    gotoxy(50,21);
                    textcolor(LIGHTGREEN);
                    printf("Login Accepted");
                    gotoxy(1,23);
                    textcolor(WHITE);
                    printf("Press any key to continue.");
                    _getch();
                    while(1)
                    {
                        adminMenuStyle();
                        fflush(stdin);
                        scanf("%d",&choice);
                        if(choice==7)
                        {
                            clrscr();
                            break;
                        }
                        switch(choice)
                        {
                            case 1:
                                clrscr();
                                addEmployeeStyle();
                                addEmployee();
                                break;
                            case 2:
                                clrscr();
                                 addCarDetailsStyle();
                                addCarDetails();

                                break;
                            case 3:
                                clrscr();
                                viewEmployeeStyle();
                                viewEmployee();
                                break;
                            case 4:
                                clrscr();
                                showCarDetailsStyle();
                                showCarDetails();
                                break;
                            case 5:

                                do
                                {
                                clrscr();
                                deleteEmployeeStyle();
                                deleteEmployee();
                                gotoxy(5,15);
                                textcolor(WHITE);
                                fflush(stdin);
                                printf("Do you want to Delete more Y/N: ");
                                scanf("%c",&ch);
                                }while(ch=='y'||ch=='Y');
                                break;
                            case 6:
                                do
                                {
                                clrscr();
                                deleteCarDetailsStyle();
                                deleteCarDetails();
                                gotoxy(5,15);
                                textcolor(WHITE);
                                fflush(stdin);
                                printf("Do you want to Delete more Y/N: ");
                                scanf("%c",&ch);
                                }while(ch=='y'||ch=='Y');
                                break;
                            case 0:
                                gotoxy(1,22);
                                printf("\t\t\t");
                                gotoxy(1,22);
                                textcolor(LIGHTGREEN);
                                printf("[HELP]");
                                gotoxy(1,23);
                                printf("Give input:");
                                gotoxy(2,24);
                                printf("1 for Add Employee");
                                gotoxy(2,25);
                                printf("3 for Add Car Details");
                                gotoxy(2,26);
                                printf("4 for Show Employee Details");
                                gotoxy(2,27);
                                printf("5 for Show Car Details");
                                gotoxy(3,28);
                                printf("AND SO ON...");
                                gotoxy(2,29);
                                textcolor(WHITE);
                                printf("Press any key to re-enter.");
                                _getch();
                                choice=9;
                                break;
                            default :
                                gotoxy(52,22);
                                textcolor(RED);
                                printf("INVALID INPUT");
                                gotoxy(46,24);
                                textcolor(WHITE);
                                printf("Press any key to re-enter");
                                _getch();
                        }
                    }
                }
            }
            else if(type==2)
            {
                 do
                {
                    loginPanelStyle(2);
                    usr=getInput();
                    if(usr!=NULL)
                    {
                        k=checkUserExist(*usr,"emp");
                    }
                    else
                    {
                        break;
                    }
                }while(k==0);
                if(k==1)
                {
                   gotoxy(50,21);
                    textcolor(LIGHTGREEN);
                    printf("Login Accepted");
                    gotoxy(1,23);
                    textcolor(WHITE);
                    printf("Press any key to continue.");
                    _getch();

                while(1)
                {
                    employeeMenuStyle();
                    fflush(stdin);
                    scanf("%d",&choice);
                    if(choice==5)
                    {
                        break;
                    }
                    switch(choice)
                    {
                    case 0:
                            gotoxy(1,19);
                                printf("\t\t\t");
                                gotoxy(1,19);
                                textcolor(LIGHTGREEN);
                                printf("[HELP]");
                                gotoxy(1,20);
                                printf("Give input:");
                                gotoxy(1,21);
                                printf("1 for Rent A CAR");
                                gotoxy(1,22);
                                printf("2 for Booking Details");
                                gotoxy(1,23);
                                printf("3 for Available Car Details");
                                gotoxy(1,24);
                                printf("4 for Show All Car Details");
                                gotoxy(1,25);
                                printf("5 for Exit");
                                gotoxy(1,26);
                                textcolor(WHITE);
                                printf("Press any key to re-enter");
                                _getch();
                                choice=10;
                                break;
                    case 1:
                        b=availableCars();
                        a=unavailableCars(b);
                        rentCar(a);
                        break;

                    case 2:
                        clrscr();
                        bookingDetailsStyle();
                        bookingDetails();
                        _getch();
                        break;
                    case 3:
                        clrscr();
                        availableCars(0);
                        _getch();
                        break;
                    case 4:
                        clrscr();
                         b=availableCars();
                        a=unavailableCars(b);
                        _getch();
                        break;
                    default :
                                gotoxy(52,20);
                                textcolor(RED);
                                printf("INVALID INPUT");
                                gotoxy(48,22);
                                textcolor(WHITE);
                                printf("Press any key to re-enter");
                                _getch();
                    }

                }
                }
            }


            else if(type==0)
            {
                pg2help();
            }
            else
            {
                gotoxy(51,20);
                textcolor(RED);
                printf("INVALID INPUT");
                gotoxy(45,22);
                textcolor(LIGHTGREEN);
                printf("Press any key to re-input");
                _getch();
                gotoxy(48,20);
                printf("\t\t\t");
                gotoxy(45,22);
                printf("\t\t\t\t");
                gotoxy(67,14);
                printf("\t\t");
                textcolor(WHITE);
                gotoxy(67,14);
                fflush(stdin);
            }
        }while(type!=1&&type!=2);
    }
    return 0;
}
