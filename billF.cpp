#include <iostream>
#include "gotoxy.h"

using namespace std;

// Prototipo de la funcion que imprime una factura del cliente en una posicion
void printBill(int pos);

// Se declara la funcion printBill que muestra la factura del cliente
void printBill(int pos)
{
    system("cls");
    gotoxy(90, 5);
    cout << "IMPORTACIONES A&D" << endl;
    gotoxy(90, 9);
    cout << "FACTURA DE COMPRA" << endl;
    gotoxy(42, 13);
    cout << "DATOS DEL CLIENTE" << endl;
    gotoxy(42, 15);
    cout << "Nombre: " << customers[pos].name << " " << customers[pos].lastName << endl;
    gotoxy(42, 17);
    cout << "Direccion: " << customers[pos].address << endl;
    gotoxy(42, 19);
    cout << "Correo electronico: " << customers[pos].email << endl;
    gotoxy(42, 21);
    cout << "Numero de telefono: " << customers[pos].cellPhoneNumber << endl;
    gotoxy(42, 25);
    cout<<"CONCEPTO"<<endl;
    gotoxy(40, 27);
    cout<<cars[pos].brand<<" "<<cars[pos].model<<" "<<cars[pos].year<<endl;
    gotoxy(60, 25);
    cout<<"CANTIDAD"<<endl;
    gotoxy(63, 27);
    cout<<"1"<<endl;
    gotoxy(80, 25);
    cout<<"PRECIO"<<endl;
    gotoxy(80, 27);
    cout<<cars[pos].price<<endl;
    gotoxy(100, 25);
    cout<<"TOTAL"<<endl;
    gotoxy(100, 27);
    cout<<cars[pos].price<<endl;
    gotoxy(38, 28);
    cout<<"________________________________________________________________________________________________________"<<endl;
    gotoxy(79, 31);
    cout<<"SUBTOTAL"<<endl;
    gotoxy(100, 31);
    cout<<cars[pos].price<<endl;
    gotoxy(74, 34);
    cout<<"TOTAL A PAGAR"<<endl;
    gotoxy(100, 34);
    cout<<cars[pos].price<<endl;
    gotoxy(38, 35);
    cout<<"________________________________________________________________________________________________________"<<endl;
    gotoxy(85, 38);
    cout<<"GRACIAS POR SU COMPRA!"<<endl;

    gotoxy(3, 38);
    system("pause");
}
