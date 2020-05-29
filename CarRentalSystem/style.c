#include"conio2.h"
#include<stdio.h>
#include<string.h>
#include"style.h"
void frontpg()
{
  gotoxy(43,11);
    textcolor(YELLOW);
    printf("WELCOME TO THE CAR RENTAL SYSTEM");
    gotoxy(39,14);
    textcolor(LIGHTGREEN);
    printf("* RENT A CAR AND GO WHEREVER YOU NEED *");
    gotoxy(58,15);
    _getch();
    textcolor(YELLOW);
}
void page2()
{
    clrscr();
        gotoxy(49,4);
        textcolor(LIGHTRED);
        printf("CAR RENTAL SYSTEM");
        gotoxy(1,8);
        textcolor(YELLOW);
        int i;
            for(i=0;i<110;i++)
            {
                printf("*");
            }
        gotoxy(1,18);
        textcolor(YELLOW);
            for(i=0;i<110;i++)
            {
                printf("*");
            }
        gotoxy(52,10);
        printf("1.ADMIN");
        gotoxy(52,12);
        printf("2.EMPLOYEE");
         gotoxy(1,23);
        textcolor(GREEN);
        printf("Give '0' to HELP");
        gotoxy(48,14);
        textcolor(WHITE);
        printf("Select your role : ");

}
void pg2help()
{
    gotoxy(1,23);
    textcolor(GREEN);
    printf("\t\t\t\t\t");
    gotoxy(1,23);
    printf("[HELP]\nGive input '1' for ADMIN.\nGive input '2' for EMPLOYEE.");
    _getch();
     gotoxy(67,14);
    printf("\t\t");
    textcolor(WHITE);
    gotoxy(67,14);
}

void loginPanelStyle(int x)
{
        clrscr();
        gotoxy(49,4);
        textcolor(YELLOW);
        printf("CAR RENTAL SYSTEM");
        gotoxy(1,6);
        int i;
        for(i=0;i<111;i++)
        {
          printf("%c",248);
        }
        gotoxy(50,9);
        printf("* LOGIN PANEL *");
        gotoxy(1,12);
        textcolor(LIGHTCYAN);
        for(i=0;i<111;i++)
        {
          printf("%c",247);
        }
        gotoxy(90,13);
        textcolor(WHITE);
        printf("Press 0 to exit");
        if(x==2)
        {
        gotoxy(1,25);
          textcolor(YELLOW);
          printf("[");
          textcolor(LIGHTGREEN);
          printf("HELP");
           textcolor(YELLOW);
          printf("]\n");
          textcolor(LIGHTGREEN);
          printf("->Emoployee id should be start with 'Emp-'.\n");
          printf("->Password should be less than 20 characters.");

        }
        gotoxy(1,19);
        textcolor(LIGHTCYAN);
        for(i=0;i<111;i++)
        {
          printf("%c",247);
        }
        gotoxy(48,15);
        printf("Enter user id : ");

        fflush(stdin);
        textcolor(WHITE);
}

void adminMenuStyle()
{
    clrscr();
    gotoxy(49,4);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(52,7);
    textcolor(GREEN);
    printf("ADMIN MENU");
    gotoxy(1,9);
    textcolor(YELLOW);
    int i;
    for(i=0;i<111;i++)
    {
        printf("*");
    }
    gotoxy(50,11);
    textcolor(YELLOW);
    printf("1. Add Employee");
    gotoxy(50,12);
    printf("2. Add Car Details");
    gotoxy(50,13);
    printf("3. Show Employee");
    gotoxy(50,14);
    printf("4. Show Car Details");
    gotoxy(50,15);
    printf("5. Delete Employee");
    gotoxy(50,16);
    printf("6. Delete Car Details");
    gotoxy(50,17);
    printf("7. Exit");
    gotoxy(1,22);
    textcolor(LIGHTGREEN);
    printf("Enter input 0 to HELP");

    gotoxy(50,19);
    textcolor(YELLOW);
    printf("Enter Choice: ");

}

void addEmployeeStyle()
{
    gotoxy(48,4);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,6);
    textcolor(YELLOW);
    int i;
    for(i=0;i<111;i++)
    {
        printf("*");
    }
    gotoxy(41,8);
    textcolor(WHITE);
    printf("***** ADD EMPLOYEE DETAILS *****");
}
void addCarDetailsStyle()
{
    gotoxy(48,4);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,6);
    textcolor(YELLOW);
    int i;
    for(i=0;i<111;i++)
    {
        printf("*");
    }
    gotoxy(44,8);
    textcolor(WHITE);
    printf("***** ADD CAR DETAILS *****");
}
void viewEmployeeStyle()
{
    gotoxy(48,4);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,6);
    textcolor(YELLOW);
    int i;
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(44,8);
    textcolor(YELLOW);
    printf("*** EMPLOYEE DETAILS ***");
    gotoxy(1,10);
    textcolor(GREEN);
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,12);
    for(i=0;i<110;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,11);
    printf("Employee ID");
    gotoxy(20,11);
    printf("Employee Name");
    gotoxy(40,11);
    printf("Employee Password");

}
void showCarDetailsStyle()
{
    gotoxy(48,4);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,6);
    textcolor(YELLOW);
    int i;
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(47,8);
    textcolor(YELLOW);
    printf("*** CAR DETAILS ***");
    gotoxy(1,10);
    textcolor(GREEN);
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,12);
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,11);
    printf("CAR ID");
    gotoxy(20,11);
    printf("CAR Name");
    gotoxy(40,11);
    printf("CAPACITY");
    gotoxy(60,11);
    printf("NUMBER OF CARS");
    gotoxy(83,11);
    printf("PRICE");
}
void deleteEmployeeStyle()
{
    gotoxy(48,4);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,6);
    textcolor(YELLOW);
    int i;
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(44,8);
    textcolor(YELLOW);
    printf("*** DELETE EMPLOYEE RECORD ***");
    gotoxy(1,10);
    textcolor(GREEN);
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
}

void deleteCarDetailsStyle()
{
    gotoxy(48,4);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,6);
    textcolor(YELLOW);
    int i;
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(46,8);
    textcolor(YELLOW);
    printf("*** DELETE CAR RECORD ***");
    gotoxy(1,10);
    textcolor(GREEN);
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
}

void employeeMenuStyle()
{
    clrscr();
    gotoxy(48,4);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(50,7);
    textcolor(GREEN);
    printf("EMPLOYEE MENU");
    gotoxy(1,9);
    textcolor(YELLOW);
    int i;
    for(i=0;i<111;i++)
    {
        printf("*");
    }
    gotoxy(50,11);
    textcolor(YELLOW);
    printf("1. Rent A CAR");
    gotoxy(50,12);
    printf("2. BOOKING DETAILS");
    gotoxy(50,13);
    printf("3. AVAILABLE CAR DETAILS");
    gotoxy(50,14);
    printf("4. SHOW ALL CAR DETAILS");
    gotoxy(50,15);
    printf("5. EXIT");
    gotoxy(1,19);
    textcolor(LIGHTGREEN);
    printf("Enter input 0 to HELP");

    gotoxy(50,17);
    textcolor(YELLOW);
    printf("Enter Choice: ");

}
void rentCarStyle()
{
    clrscr();
    gotoxy(48,4);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(46,6);
    textcolor(WHITE);
    printf("*** EMPLOYEE MENU ***");
    gotoxy(48,9);
    textcolor(GREEN);
    printf("AVAILABLE CARS");
    gotoxy(1,10);
    textcolor(GREEN);
    int i;
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,12);
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,11);
    printf("CAR ID");
    gotoxy(20,11);
    printf("CAR Name");
    gotoxy(40,11);
    printf("CAPACITY");
    gotoxy(60,11);
    printf("NUMBER OF CARS");
    gotoxy(83,11);
    printf("PRICE");
}
void bookingDetailsStyle()
{
    gotoxy(48,4);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    gotoxy(46,6);
    textcolor(WHITE);
    printf("*** BOOKING DETAILS ***");

    gotoxy(1,8);
    textcolor(GREEN);
    int i;
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,10);
    for(i=0;i<111;i++)
    {
        printf("%c",247);
    }
    gotoxy(2,9);
    printf("Model");
    gotoxy(14,9);
    printf("Cust Name");
    gotoxy(30,9);
    printf("Pick Up");
    gotoxy(45,9);
    printf("Drop");
    gotoxy(60,9);
    printf("S_date");
    gotoxy(74,9);
    printf("S_date");
}











