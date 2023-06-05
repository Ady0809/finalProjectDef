#include<iostream>
#include <string.h>
#include "carF.cpp"
#define MAX 100

using namespace std;

typedef struct{
    int id;
    char name[20];
    char lastName[20];
    char address[50];
    char email[20];
    char cellPhoneNumber[15];
    carData car;
}customerData;

customerData customers[MAX];
int lastRecord = 0;

void addCustomer(customerData customer);
void showCustomer(int pos);
int customerExists(int id);
void showCustomers();
customerData getCustomer(int pos);
void initCustomer(int pos);
void editCustomer(customerData customer, int pos);
void deleteCustomer(int pos);

FILE *customerRegister;
void saveCustomers();
void readCustomers();
int getLastRecord(FILE *file);

void addCustomer(customerData customer)
{
    customer.id = lastRecord + 1;
    customers[lastRecord] = customer;
    lastRecord++;
}

void showCustomer(int pos)
{
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\tCUSTOMER INFO" << endl;
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "|       ID       |      Name      |      Last name    |              Address          |           Email          |      Cellphone #      |" << endl;
    cout << "_________________________________________________________________________________________________________________" << endl;
    cout << "|        " << customers[pos].id << "       |      " << customers[pos].name << "   |        " << customers[pos].lastName << "|" << customers[pos].address << "|" << customers[pos].email << "|" << customers[pos].cellPhoneNumber << "|" << endl;
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\tCAR INFO" << endl;
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "|       ID       |      Kind      |      Brand    |           Model          |           Color          |      Transmission      |      Year      |       Price     |" << endl;
    cout << "|" << cars[pos].id << "|" << cars[pos].kind << "|" << cars[pos].brand << "|" << cars[pos].model << "|" << cars[pos].color << "|" << cars[pos].transmission << "|" << cars[pos].year << "|" << cars[pos].price << "|\n\n\n";
    cout << "_______________________________________________________________________________________________________________" << endl;
}
