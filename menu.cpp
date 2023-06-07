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
