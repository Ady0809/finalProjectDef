#include <iostream>
#include <string.h>
#define MAX 100

using namespace std;

typedef struct
{
    int id;
    char kind[10];
    char brand[10];
    char model[15];
    char color[10];
    char transmission[5];
    char year[4];
    float price;
} carData;

carData cars[MAX];
int lastCar = 0;

void addCar(carData car);
int carExists(int id);
void showCar(int pos);
void showCars();
void initCar();
carData getCar(int pos);

void addCar(carData car)
{  
    cars[lastCar] = car;
    lastCar++;
}
