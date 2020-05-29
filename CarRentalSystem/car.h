#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
typedef struct user
{
    char userid[20];
    char pwd[20];
    char name[20];
}user;
typedef struct car
{
    int carid;
    char carName[50];
    int capacity;
    int carCount;
    int price;
}car;
typedef struct custDetails
{
    char carname[30];
    char custName[30];
    char pick[30];
    char drop[30];
    struct tm sd;
    struct tm ed;
}cust;

void addAdmin();
user* getInput();
int checkUserExist(user,char*);
void addEmployee();
void sub_str(char*,char*,char);
void addCarDetails();
void viewEmployee();
void showCarDetails();
void deleteEmployee();
void deleteCarDetails();
void rentCar();
void switchDefault();
void bookingDetails();


int availableCars();
int unavailableCars(int);
int isValidDate(struct tm);

int checkBlankInput(char*,int);
int onlyIntegerInput(int ,int );


#endif // CAR_H_INCLUDED
