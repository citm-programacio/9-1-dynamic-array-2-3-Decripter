#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

int* ampliar(int *matriz, int tamano)
{
    int* nueva = new int[tamano + 1];
    for (int i = 0; i < tamano; i++)
    {
        nueva[i] = matriz[i];
    };

    return nueva;
};

void imprimir(int *matriz, int tamano)
{
   
    cout << endl << "Matriz:  [";
    for (int i = 0; i <= tamano; i++)
    {
        cout << " " << matriz[i] << " ";
    };
    cout << "]" << endl;
};

int main()
{
    srand(time(nullptr));
    int tamano = 0;
    int * matriz = new int [0];
    int numero;
    int aux;
    

    char opcion;

    cout << "A: Agregar numero       "<< "S: Salir e imprimir" << endl;

    do
    {
        cout << "Ingresa opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 'a':
            matriz = ampliar(matriz, tamano);
            cout << "ingresa numero: ";
            cin >> numero;
            

            matriz[tamano] = numero;

            //bubble sort
            for (int i = 0; i < tamano; i++)
            {
                for (int x = 0; x < tamano; x++)
                {
                    if (matriz[x] > matriz[x + 1])
                    {
                        aux = matriz[x];
                        matriz[x] = matriz[x + 1];
                        matriz[x + 1] = aux;
                    };
                };
            };


            imprimir(matriz, tamano);
            tamano++;

            break;

        case 's':
            break;
        };
    }
    while (opcion != 's');

    tamano--;

    char ran;
    cout << "Randomizar? (Y/N)" << endl;
    cin >> ran;
    switch (ran)
    {
    case 'y':
        for (int i = 0; i < tamano; i++)
        {
           int x = rand() % tamano;
           int y = rand() % tamano;

           int aux = matriz[x];
           matriz[x] = matriz[y];
           matriz[y] = aux;
        };

        break;
    case 'n':
        break;
    };

    cout << endl << "MATRIZ FINAL:";
    imprimir(matriz, tamano);
}
