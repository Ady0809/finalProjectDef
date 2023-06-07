#include <iostream>
#include <string.h>
#include "carF.cpp"

#define MAX 100

using namespace std;

//Se define estructura de datos para el cliente
typedef struct
{
    int id;
    char name[20];
    char lastName[20];
    char address[50];
    char email[20];
    char cellPhoneNumber[15];
    carData car;
    // Nombre de la estructura customerData
} customerData;

//Se define el arreglo customer de tipo customerData con un tamaño de MAX
customerData customers[MAX];

//Se define la variable lastRecord que se utiliza para llevar el numero de los registros
int lastRecord = 0;

// Prototipo de la funcion que agrega clientes
void addCustomer(customerData customer);

//Prototipo de la funcion que muestra UN cliente
void showCustomer(int pos);

// Prototipo de la funcion que verifica si un cliente existe
int customerExists(int id);

// Prototipo de la funcion que muestra TODOS los clientes
void showCustomers();

// Prototipo de la funcion que retorna un cliente y sus datos
customerData getCustomer(int pos);

// Prototipo de la funcion que inicializa los datos de un cliente
void initCustomer(int pos);

// Prototipo de la funcion que edita los datos de un cliente
void editCustomer(customerData customer, int pos);

// Prototipo de la funcion que elimina un cliente
void deleteCustomer(int pos);

//Se declara variable customerRegister de tipo FILE (archivo)
FILE *customerRegister;

// Prototipo de la funcion que guarda los clientes en el archivo
void saveCustomers();

// Prototipo de la funcion que lee los clientes del archivo
void readCustomers();

// Prototipo de la funcion que retorna el numero de clientes
int getLastRecord(FILE *file);

// Se declara la funcion addCustomer que recibe como parametro una variable de tipo customerData
void addCustomer(customerData customer)
{
    customer.id = lastRecord + 1;
    customers[lastRecord] = customer;
    lastRecord++;
}

//Se declara la funcion showCustomer que recibe como parametro la posicion de tipo entero
void showCustomer(int pos)
{   
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\tCUSTOMER INFO" << endl;
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "|       ID       |      Name      |      Last name    |              Address          |           Email          |      Cellphone #      |" << endl;
    cout << "_________________________________________________________________________________________________________________" << endl;
    cout << "|        " << customers[pos].id << "       |      " << customers[pos].name << "   |        " << customers[pos].lastName << "|" << customers[pos].address << "|" << customers[pos].email << "|" << customers[pos].cellPhoneNumber << "|" << endl;
    cout << "_____________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\tCAR INFO" << endl;
    cout << "_____________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "|       ID       |      Kind      |      Brand    |           Model          |           Color          |      Transmission      |      Year      |       Price     |" << endl;
    cout << "|      " << cars[pos].id<< "     |" << cars[pos].kind << "|" << cars[pos].brand << "|" << cars[pos].model << "|" << cars[pos].color << "|" << cars[pos].transmission << "|" << cars[pos].year << "|" << cars[pos].price << "|\n\n\n";
    cout << "_____________________________________________________________________________________________________________________________________________________________________" << endl;
}

// Se declara la funcion getCustomer que recibe como parametro la posicion de tipo entero
customerData getCustomer(int pos)
{
    return customers[pos];
}

// Se declara la funcion customerExists que recibe como parametro el id
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

// Se declara la funcion showCustomers que muestra todos los clientes
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

// Se declara la funcion editCustomer que actualiza los datos del cliente en una posicion determinada
void editCustomer(customerData customer, int pos)
{
    customers[pos] = customer;
}

// Se declara la funcion deleteCustomer que elimina un cliente en una determinada posicion
void deleteCustomer(int pos)
{
    if (pos == lastRecord || pos < 0)
    {
        cout << "No records available" << endl;
        return;
    }
    for (int i = pos; i < lastRecord - 1; i++)
    {
        customers[i] = customers[i + 1];
    }
    lastRecord--;
    initCustomer(lastRecord);
}

// Se declara la funcion initCustomer que inicializa los datos de un cliente
void initCustomer(int pos)
{
    customers[pos].id = 0;
    strcpy(customers[pos].name, "");
    strcpy(customers[pos].lastName, "");
    strcpy(customers[pos].address, "");
    strcpy(customers[pos].email, "");
    strcpy(customers[pos].cellPhoneNumber, "");
}

// saveCustomers abre un archivo en modo escritura y guarda los clientes
void saveCustomers()
{
    customerRegister = fopen("records.txt", "wb");
    fwrite(customers, sizeof(customerData), lastRecord, customerRegister);
    fclose(customerRegister);
}

// readCustomers abre un archivo en modo lectura y lee los clientes
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

// getLastRecord retorna el numero de clientes
int getLastRecord(FILE *file)
{
    int tam_archivo, num_clientes;
    // Obtener el tamaño del archivo
    fseek(file, 0, SEEK_END);
    tam_archivo = ftell(file);
    rewind(file);

    // Calcular el número de clientes
    num_clientes = tam_archivo / sizeof(customerData);
    return num_clientes;
}
