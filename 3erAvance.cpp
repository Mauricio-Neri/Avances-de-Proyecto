#include <iostream> // Bibliotecas que usa el codigo
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Tienda // Uso de estructuras para que el codigo sea mas corto y pueda guardar todos los datos que piden porque las estructuras guardan todo tipo de dato
{
    string art[100], des[100], clas[100], con[100], gen[100];
    float prec, tprec, nart;
    char status;
};

Tienda* Videojuegos; // Uso de punteros
int contador = 0;

void Articulos(); // Declaracion de funciones void
void Modificacion();
void Baja();
void Lista();
void Archivo();

int main()
{
    int opcion;
    Videojuegos = new Tienda[100];

    do // Do while para el menu de opciones, asi sea que se ingrese un numero de seleccion incorrecto termine el programa
    {
        cout << "\t ***MENU DE OPCIONES***" << endl;
        cout << "1. Articulos" << endl;
        cout << "2. Modificacion de Articulos" << endl;
        cout << "3. Baja de Articulos" << endl;
        cout << "4. Lista de Articulos" << endl;
        cout << "5. Limpiar Pantalla" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1: // Esta opcion da de alta articulos de la tienda cuando se presiona el numero "1", esta opcion te lleva directo a la funcion void de Articulos donde se ingresaran los articulos
            Articulos();
            break;
        case 2: // Esta opcion permite modificar los articulos ya dados de alta cuando se presiona el numero "2", esta opcion te lleva directo a la funcion void de Modificacion donde podras modificar los articulos. No habra modificacion si el articulo no es dado de alta primero
            Modificacion();
            break;

        case 3: // Esta opcion da de baja/elimina articulos ya dados de alta cuando se presiona el numero "3", esta opcion te lleva directo a la funcion void de Baja donde podras dar de baja los articulos. Solo se podran dar de baja los articulos que ya esten dados de alta y una vez hecho ya no se puede revertir
            Baja();
            break;

        case 4: // Esta opcion te da la Lista de los articulos ya dados de alta, tambien incluyen los eliminados, cuando se presiona el numero "4", esta opcion te lleva directo a la funcion void de Lista donde podras ver todos los articulos
            Lista();
            break;

        case 5: // Esta opcion limpia la pantalla al presionar el numero "5" con la funcion de system("cls")
            system("cls");
            break;
        case 6: // Esta opcion permite guardar la informacion ya dada por el usuario y cerrando la pantalla simultaneamente al presionar el numero "6", esta opcion te lleva primero a la funcion void de Archivo donde se guardara toda la informacion que el usuario le de al codigo, incluyendo las eliminadas, y despues de guardar todo en un archivo se cierra la pantalla con la funcion exit(1)
            Archivo();
            exit(1); // cierra la pantalla
            break;
        }
    } while (opcion != 6);

    delete[] Videojuegos; // Liberar la memoria asignada

    return 0;
}

void Articulos() // Aqui se ingresan todos los datos de los articulos que desea dar de alta
{
    cout << "¿Cuántos registros desea dar de alta?" << endl;
    cin >> contador;
    for (int i = 0; i < contador; i++)
    {
        cout << "Ingrese número del item: ";
        cin >> Videojuegos[i].nart;

        cin.ignore(); // Ignorar el salto de línea anterior

        cout << "Ingrese nombre del item: ";
        getline(cin, Videojuegos[i].art);

        cout << "Ingrese descripción del item: ";
        getline(cin, Videojuegos[i].des);

        cout << "Ingrese genero del item: ";
        getline(cin, Videojuegos[i].gen);

        cout << "Ingrese clasificacion del item: ";
        getline(cin, Videojuegos[i].clas);

        cout << "Ingrese consola del item: ";
        getline(cin, Videojuegos[i].con);

        cout << "Ingrese precio del item sin el IVA incluido: ";
        cin >> Videojuegos[i].prec;
    }
}

void Lista() // Aqui la funcion te permitira que veas la lista de todos los articulos
{
    for (int i = 0; i < contador; i++)
    {
        if (Videojuegos[i].status == 'E')
        {
            cout << "Articulo eliminado" << endl;
        }
        else
        {
            cout << "Articulo: " << i + 1 << endl; // Numero asignado al articulo, este se usara para modificar y eliminar
            Videojuegos[i].tprec = Videojuegos[i].prec * 1.6; // El precio con el IVA incluido
            cout << "Numero del Item: " << Videojuegos[i].nart << endl;
            cout << "Nombre del Item: " << Videojuegos[i].art << endl;
            cout << "Descripcion del Item: " << Videojuegos[i].des << endl;
            cout << "Genero del Item: " << Videojuegos[i].gen << endl;
            cout << "Clasificacion del Item: " << Videojuegos[i].clas << endl;
            cout << "Consola del Item: " << Videojuegos[i].con << endl;
            cout << "Precio del Item: " << Videojuegos[i].prec << endl;
            cout << "Precio del Item con IVA: " << Videojuegos[i].tprec << endl;
        }
    }
}

void Baja() // Aqui los articulos se dan de baja ingresando el numero del articulo proporcionado en la Lista
{
    int j;
    cout << "Ingrese el numero de registro a eliminar: ";
    cin >> j;
    j = j - 1;
    for (int i = j; i == j; i++)
    {
        cout << "Eliminando registro " << j + 1 << endl;
        Videojuegos[i].status = 'E'; // "E" de Eliminado
        Videojuegos[i].nart = 0;
        Videojuegos[i].art = "";
        Videojuegos[i].des = "";
        Videojuegos[i].gen = "";
        Videojuegos[i].clas = "";
        Videojuegos[i].con = "";
        Videojuegos[i].prec = 0;
        Videojuegos[i].tprec = 0;
    }
}

void Modificacion() // Aqui los articulos se pueden modificar ingresando el numero del articulo proporcionado por la lista
{
    int j, opcion, op2;
    do
    {
        cout << "Ingrese numero del registro que desea modificar: ";
        cin >> j;
        j = j - 1; // i comienza en 0, por lo tanto se le tiene que restar al numero ingresado para que no haya problemas. Esto no afectara articulos que no se desean eliminar, asi que no hay de que preocuparse

        for (int i = j; i == j; i++)
        {
            if (Videojuegos[i].status == 'E') // Validacion en caso de que el articulo sea eliminado
            {
                cout << "Registro eliminado" << endl;
                cout << "Ingrese un registro VALIDO" << endl;
                op2 = 1;
            }
            else
            {
                op2 = 2;
            }
        }
    } while (op2 == 1);

    cout << "Ingrese la opcion que desea modificar:" << endl;
    cout << "1. Numero del item" << endl;
    cout << "2. Nombre del Item" << endl;
    cout << "3. Descripcion del Item" << endl;
    cout << "4. Genero del Item" << endl;
    cout << "5. Clasificacion del Item" << endl;
    cout << "6. Consola" << endl;
    cout << "7. Precio" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        for (int i = j; i == j; i++)
        {
            cout << "Ingrese nuevo numero del item: ";
            cin >> Videojuegos[i].nart;
        }
        break;
    case 2:
        for (int i = j; i == j; i++)
        {
            cin.ignore(); // Ignorar el salto de línea anterior
            cout << "Ingrese nuevo nombre del item: ";
            getline(cin, Videojuegos[i].art);
        }
        break;

    case 3:
        for (int i = j; i == j; i++)
        {
            cin.ignore(); // Ignorar el salto de línea anterior
            cout << "Ingrese nueva descripcion del item: ";
            getline(cin, Videojuegos[i].des);
        }
        break;
    case 4:
        for (int i = j; i == j; i++)
        {
            cin.ignore(); // Ignorar el salto de línea anterior
            cout << "Ingrese nuevo genero del item: ";
            getline(cin, Videojuegos[i].gen);
        }
        break;

    case 5:
        for (int i = j; i == j; i++)
        {
            cin.ignore(); // Ignorar el salto de línea anterior
            cout << "Ingrese nueva clasificacion del item: ";
            getline(cin, Videojuegos[i].clas);
        }
        break;

    case 6:
        for (int i = j; i == j; i++)
        {
            cin.ignore(); // Ignorar el salto de línea anterior
            cout << "Ingrese consola del item: ";
            getline(cin, Videojuegos[i].con);
        }
        break;

    case 7:
        for (int i = j; i == j; i++)
        {
            cin.ignore(); // Ignorar el salto de línea anterior
            cout << "Ingrese nuevo precio del item sin IVA: ";
            cin >> Videojuegos[i].prec; // El precio sin el IVA
            Videojuegos[i].tprec = Videojuegos[i].prec * 1.6; // El precio con el IVA incluido
        }
        break;
    }
}

void Archivo() // Aqui se guardan todos los datos del programa
{
    ofstream archivo; //clase ofstream para escribir archivos
    string nombrearchivo;
    int texto;
    string texto2;

    nombrearchivo = "articulostienda.txt";

    archivo.open(nombrearchivo.c_str(), ios::out);

    if (!archivo)
    {
        cout << "ERROR: No se pudo crear el archivo" << endl;
        exit(1);
    }

    archivo << "NUMERO DE ITEM" << "\t";
    archivo << "NOMBRE ARTICULO" << "\t";
    archivo << "DESCRIPCION" << "\t";
    archivo << "GENERO" << "\t";
    archivo << "CLASIFICACION" << "\t";
    archivo << "CONSOLA" << "\n";
    archivo << "PRECIO" << "\n";
    archivo << "PRECIO CON IVA" << "\n";
    archivo << "STATUS" << "\n";

    for (int i = 0; i < contador; i++)
    {
        if (Videojuegos[i].status == 'E')
        {
            texto2 = "REGISTRO ELIMINADO ";
            texto = i;
            archivo << texto2 << texto << "\n";
        }
        else
        {
            texto = Videojuegos[i].nart;
            archivo << texto << "\t" << "\t";
            texto2 = Videojuegos[i].art;
            archivo << texto2 << "\t" << "\t";
            texto2 = Videojuegos[i].des;
            archivo << texto2 << "\t " << "\t";
            texto2 = Videojuegos[i].gen;
            archivo << texto2 << "\t " << "\t";
            texto2 = Videojuegos[i].clas;
            archivo << texto2 << "\t " << "\t";
            texto2 = Videojuegos[i].con;
            archivo << texto2 << "\t " << "\t";
            texto = Videojuegos[i].prec;
            archivo << texto << "\t " << "\t";
            texto = Videojuegos[i].tprec;
            archivo << texto << "\t " << "\t";
        }
    }

    archivo.close();
}
