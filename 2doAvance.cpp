#include <iostream>
#include <math.h>
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
using  namespace std;

struct tienda
{
    char art[20], des[30], clas[20], con[20], gen[20];
    float prec, tprec, nart;

};

int main()
{
    tienda videojuegos[3];
    int opcion;
    do
    {
        printf("\t ***MENU DE OPCIONES***");
        printf("1. Articulos");
        printf("2. Modificacion de Articulos");
        printf("3. Baja de Articulos");
        printf("4. Lista de Articulos");
        printf("5. Limpiar Pantalla");
        printf("6. Salir");
        scanf_s("%d", &opcion);

        switch (opcion)
        {
        case 1: //ALTA
            for (int i = 0; i < 3; i++)
            {
                printf("Ingrese numero del item \n");
                scanf_s("%f", &videojuegos[i].nart);
                printf("Ingrese nombre del item \n");
                scanf_s("%s", &videojuegos[i].art);
                printf("Ingrese descripcion del item \n");
                scanf_s("%s", &videojuegos[i].des);
                printf("Ingrese genero del item \n");
                scanf_s("%s", &videojuegos[i].gen);
                printf("Ingrese clasificacion del item \n");
                scanf_s("%s", &videojuegos[i].clas);
                printf("Ingrese consola del item \n");
                scanf_s("%s", &videojuegos[i].con);
                printf("Ingrese precio del item \n");
                scanf_s("%f", &videojuegos[i].prec);
                cin.ignore();
                
            }
            break;
        case 2:
            break;

        case 3:
            break;

        case 4: //LISTA
            for (int i = 0; i < 3; i++)
            {
                tprec=videojuegos[i]*1.6;
                printf("Numero del Item \t %f", videojuegos[i].nart);
                printf("Nombre del Item \t %s", videojuegos[i].art);
                printf("Descripcion del Item \t %s", videojuegos[i].des);
                printf("Genero del Item \t %s", videojuegos[i].gen);
                printf("Clasificacion del Item \t %s", videojuegos[i].clas);
                printf("Consola del Item \t %s", videojuegos[i].con);
                printf("Precio del Item \t %f", videojuegos[i].tprec);
            }
            break;

        case 5:
            system("cls"); // limpiar pantalla
            break;
        case 6:
            exit(1); // cierra la pantalla
            break;
        }
    } while (opcion!=6);
}