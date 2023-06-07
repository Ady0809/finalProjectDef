#include<iostream>
#include"gotoxy.h"

using namespace std;

void printBill(int pos);

// ESTA FUNCION IMPRIME UNA FACTURA DE UN CLIENTE EN ESPECIFICO
void printBill(int pos)
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
