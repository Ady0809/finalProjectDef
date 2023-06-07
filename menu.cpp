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

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customerF.cpp"
#include"billF.cpp"

using namespace std;

//Se declaran los prototipos de las funciones y variables globales del menu
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

//Se define la funcion mainMenu que muestra el menu principal
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

void initialize()
{   
    customerData customer;
    carData car;

    readCustomers();
    do
    {
        system("cls");
        mainMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            menuCar();
            break;

        case 2:
            system("cls");
            
            customer.id = lastRecord+1;
            cout << "ID: " << customer.id << endl;
            cout << "Name: ";
            scanf(" %[^\n]", customer.name);
            cout << "Last name: ";
            scanf(" %[^\n]", customer.lastName);
            cout << "Address: ";
            scanf(" %[^\n]", customer.address);
            cout << "Email: ";
            scanf(" %[^\n]", customer.email);
            cout << "Cellphone number: ";
            scanf(" %[^\n]", customer.cellPhoneNumber);

            system("cls");
            cout << "Customer added successfully\n\n\n\n";

            showCars();

            cout << "Enter ID of the car bought: ";
            cin >> id;

            pos = carExists(id);
            reqCar= getCar(pos);
            
            if(pos != -1)
            {
                customer.car = reqCar;
            }
            else
            {
                // Car doesn´t exists
                cout << "Invalid car ID. Car not found." << endl;
            }       

            addCustomer(customer);

            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Enter ID to search: ";
            cin >> id;
            system("cls");
            pos = customerExists(id);
            if (pos == -1)
            {
                cout << "Customer not found" << endl;
                system("pause");
                break;
            }
            else
            {
                showCustomer(pos);
            }
            system("pause");
            break;

        case 4:
        if(lastRecord == 0){
            system("cls");
            cout << "No customers registered" << endl;
            system("pause");
            break;
        }
            showCustomers();
            system("pause");
            break;

        case 5:
        system("cls");
            cout << "Enter ID to edit: ";
            cin.ignore();
            cin >> id;

            pos = customerExists(id);
            showCustomer(pos);

            cout << "\n\n\n_________________________________" << endl;
            cout << "\tNew values" << endl;
            cout << "_________________________________\n"
                    << endl;
            
            customer.id = pos+1;

            cout<<"ID: "<< customer.id <<endl;

            cout << "Name: ";   
            scanf(" %[^\n]", customer.name);

            cout << "Last name: ";
            scanf(" %[^\n]", customer.lastName);

            cout << "Address: ";
            scanf(" %[^\n]", customer.address);

            cout << "Email: ";
            scanf(" %[^\n]", customer.email);

            cout << "Cellphone #: ";
            scanf(" %[^\n]", customer.cellPhoneNumber);

            editCustomer(customer, pos);

            cout << "Customer edited succesfully!\n"
                 << endl;
            break;

        case 6:
            system("cls");
            if (lastRecord == 0)
            {
                cout << "No customers to delete\n"
                     << endl;
            }

            cout << "Enter ID to delete: ";
            cin >> id;

            pos = customerExists(id);

            deleteCustomer(pos);
            break;

        case 7:
            system("cls");
            cout<<"Enter customer ID to generate bill: ";
            cin>>id;

            pos = customerExists(id);
            reqCustomer = getCustomer(pos);

            if (pos != -1)
            {
                customer = reqCustomer;
                printBill(pos);
                
            } else {
                cout<<"Customer not found"<<endl;
            }
            
            system("pause");
            break;

        case 8:
            break;

        default:
            cout << "Unavailable choice, please try again\n";
            system("pause");
            break;
        }

    } while (choice != 8);
