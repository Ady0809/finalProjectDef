#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customerF.cpp"
#include"billF.cpp"

using namespace std;

void mainMenu();
void initialize();
void menuCar();

int choice, id, pos = -1;
char ans[4];

customerData customer;
carData car;
carData reqCar;
carData reqCar0;
customerData reqCustomer;

void mainMenu()
{
    int choice;

    cout << "___________________________________________________" << endl;
    cout << "\tCUSTOMER REGISTER SYSTEM" << endl;
    cout << "\t   Current records: " << lastRecord << endl;
    cout << "___________________________________________________\n"
         << endl;

    cout << "1. Car manage" << endl;
    cout << "2. Add customer" << endl;
    cout << "3. Search customer" << endl;
    cout << "4. Show customers" << endl;
    cout << "5. Edit customer" << endl;
    cout << "6. Delete customer" << endl;
    cout << "7. Generate bill" << endl;
    cout << "8. Exit\n\n";
    cout << "Enter your choice: ";
}
