#include <iostream> // Biblioteca
using namespace std;

void main()
{
    int opc, numart, opz; // Declaracion de variables
    float prec, tprec;
    char art[20], des[30], clas[20], con[20], gen[20];
    cout << "\t Menu de Opciones" << endl << "1. Alta de Articulos" << endl << "2. Modificacion de Articulos" << endl << "3. Baja de Articulos" << endl << "4. Lista de Articulos" << endl << "5. Limpiar Pantalla" << endl << "6. Salir" << endl; // Opciones de Menu
    cin >> opc;
    switch (opc)
    {
    case 1: // Articulos
        cout << "Numero del Item" << endl << "Nombre del articulo" << endl << "Descripcion" << endl << "Genero" << endl << "Clasificacion" << endl << "Consola" << endl << "Precio" << endl; // Declaracion del articulo a guardar
        cin >> numart >> art >> des >> gen >> clas >> con >> prec;
        return main(); // Regresa al inicio para declarar articulos las veces que sean necesarias
        break;

    case 2: // 
        return main();
        break;

    case 3:
        return main();
        break;

    case 4:
        return main();
        break;

    case 5:
        system(cls);
        break;

    default:
        exit(1);
        break;
    }
}