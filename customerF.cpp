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