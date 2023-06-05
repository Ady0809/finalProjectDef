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

customerData getCustomer(int pos)
{
    return customers[pos];
}

int customerExists(int id)
{
    int pos = -1;
    for (int i = 0; i < lastRecord; i++)
    {
        if ((id == customers[i].id))
        {
            pos = i;
            break;
        }
    }
    return pos;
}

void showCustomers()
{
    if (lastRecord == -1)
    {
        cout << "No records available" << endl;
        return;
    }
    for (int i = 0; i < lastRecord; i++)
    {
        showCustomer(i);
    }
}

void editCustomer(customerData customer, int pos)
{
    customers[pos] = customer;
}

void deleteCustomer(int pos)
{
    if (pos == lastRecord || pos < 0)
    {
        cout << "No records available" << endl;
        return;
    }
    for (int i = pos; i < lastRecord; i++)
    {
        customers[i] = customers[i + 1];
    }
    lastRecord--;
    initCustomer(lastRecord);
}

void initCustomer(int pos)
{
    customers[pos].id = 0;
    strcpy(customers[pos].name, "");
    strcpy(customers[pos].lastName, "");
    strcpy(customers[pos].address, "");
    strcpy(customers[pos].email, "");
    strcpy(customers[pos].cellPhoneNumber, "");
}

void saveCustomers()
{
    customerRegister = fopen("records.txt", "wb");
    fwrite(customers, sizeof(customerData), lastRecord, customerRegister);
    fclose(customerRegister);
}

void readCustomers()
{
    customerRegister = fopen("records.txt", "rb");
    if (customerRegister == NULL)
    {
        return;
    }
    lastRecord = getLastRecord(customerRegister);
    fread(customers, sizeof(customerData), MAX, customerRegister);

    fclose(customerRegister);
}

int getLastRecord(FILE *file)
{
    int tam_archivo, num_clientes;
    // Obtener el tamaño del archivo
    fseek(file, 0, SEEK_END);
    tam_archivo = ftell(file);
    rewind(file);

    // Calcular el número de alumnos
    num_clientes = tam_archivo / sizeof(customerData);
    return num_clientes;
}
