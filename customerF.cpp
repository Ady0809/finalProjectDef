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
