#include <iostream>
#include <string.h>

#define MAX 100

using namespace std;

// Se define estructura de datos para el carro
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
    //Nombre de la estructura carData
} carData;

// Se define el arreglo cars de tipo carData con un tamaño de MAX
carData cars[MAX];

// Se define la variable lastCar que se utiliza para llevar el numero de los carros
int lastCar = 0;

// Prototipo de la funcion que agrega carros
void addCar(carData car);

// Prototipo de la funcion que verifica si un carro existe
int carExists(int id);

//Prototipo de la funcion que muestra UN carro
void showCar(int pos);

// Prototipo de la funcion que muestra TODOS los carros
void showCars();

// Prototipo de la funcion que edita los datos de un carro
void editCar(carData car, int pos);

// Prototipo de la funcion que elimina un carro
void deleteCar(int pos);

// Prototipo de la funcion que inicializa los datos de un carro
void initCar(int pos);

// Prototipo de la funcion que retorna un carro y sus datos
carData getCar(int pos);

// Se declara variable carRegister de tipo FILE (archivo)
FILE *carRegister;

// Prototipo de la funcion que guarda los carros en el archivo
void saveCars();

// Prototipo de la funcion que lee los carros del archivo
void readCars();

// Prototipo de la funcion que retorna el numero de carros
int getLastCar(FILE *file);

// Se declara la funcion addCar que recibe como parametro un carro
void addCar(carData car)
{  
    cars[lastCar] = car;
    lastCar++;
}

// Se declara la funcion carExists que recibe como parametro un id de tipo entero
int carExists(int id)
{
    int pos = -1;
    for (int i = 0; i < lastCar; i++)
    {
        if (id == cars[i].id)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

// Se declara la funcion showCar que recibe como parametro la posicion del carro
void showCar(int pos)
{   
    cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "|\t\t\t\t\t\t\t\t\t\tCAR INFO                                                                            |" << endl;
    cout << "|___________________________________________________________________________________________________________________________________________________________________|" << endl;
    cout << "|       ID       |      Kind      |      Brand    |           Model          |           Color          |      Transmission      |      Year      |       Price     |" << endl;
    cout << "|___________________________________________________________________________________________________________________________________________________________________|" << endl;
    cout << "|       " << cars[pos].id << "        |      " << cars[pos].kind << "      |       " << cars[pos].brand << "       |" << cars[pos].model << "|" << cars[pos].color << "|" << cars[pos].transmission << "|" << cars[pos].year << "|" << cars[pos].price << "|"<<endl;
    cout << "_____________________________________________________________________________________________________________________________________________________________________" << endl;
}

// Se declara la funcion showCars que muestra todos los carros
void showCars()
{
    if (lastCar == -1)
    {
        cout << "No records available" << endl;
        return;
    }
    for (int i = 0; i < lastCar; i++)
    {
        showCar(i);
    }
}

// Se declara la funcion editCar que recibe como parametro un carro y su posicion
void editCar(carData car, int pos)
{
    cars[pos] = car;
}

// Se declara la funcion deleteCar que recibe como parametro la posicion del carro
void deleteCar(int pos)
{
    if(pos == lastCar || pos < 0)
    {
        cout << "No records available" << endl;
        return;
    }
    for(int i = pos; i < lastCar; i++)
    {
        cars[i] = cars[i+1];
    }
    lastCar--;
    initCar(lastCar);
}

// Se declara la funcion getCar que recibe como parametro la posicion del carro
carData getCar(int pos){
    return cars[pos];
}

// Se declara la funcion initCar que recibe como parametro la posicion del carro
void initCar(int pos)
{
    strcpy(cars[pos].kind, "");
    strcpy(cars[pos].brand, "");
    strcpy(cars[pos].model, "");
    strcpy(cars[pos].color, "");
    strcpy(cars[pos].transmission, "");
    strcpy(cars[pos].year, "");
    cars[pos].price = 0;
}

// saveCars abre un archivo en modo escritura y guarda los carros
void saveCars()
{
    carRegister = fopen("cars.txt", "wb");
    fwrite(cars, sizeof(carData), lastCar, carRegister);
    fclose(carRegister);
}

// readCars abre un archivo en modo lectura y lee los carros
void readCars()
{
    carRegister = fopen("cars.txt", "rb");
    if (carRegister == NULL)
    {
        return;
    }
    lastCar = getLastCar(carRegister);
    fread(cars, sizeof(carData), MAX, carRegister);

    fclose(carRegister);
}

// getLastCar retorna el numero de carros
int getLastCar(FILE *file)
{
    int tam_archivo, num_cars;
    // Obtener el tamaño del archivo
    fseek(file, 0, SEEK_END);
    tam_archivo = ftell(file);
    rewind(file);

    // Calcular el número de alumnos
    num_cars = tam_archivo / sizeof(carData);
    return num_cars;
}
