#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

struct Articulo {
    int nart;
    string art;
    string des;
    string gen;
    string clas;
    string con;
    double prec;
    string status;
}; // Uso de Estructuras

const int MAX_ARTICULOS = 100;
Articulo Videojuegos[MAX_ARTICULOS];
int contador = 0;

void Agregar();
void Modificacion();
void Baja();
void Lista();
void Archivo();

int main()
{
    int opcion;

    do
    {
        cout << "MENU" << endl; // Menu de opciones
        cout << "1. Agregar articulo" << endl;
        cout << "2. Mostrar lista de articulos" << endl;
        cout << "3. Modificar articulo" << endl;
        cout << "4. Limpiar Pantalla" << endl;
        cout << "5. Salir" << endl; // En salir se genera el archivo
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            Agregar();
            break;
        case 2:
            Lista();
            break;
        case 3:
            Modificacion();
            break;
        case 4:
            sytem("cls");
            break;
        case 5:
            Archivo();
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
        }

        cout << endl;
    } while (opcion != 5);

    return 0;
}

void Agregar()
{
    cout << "¿Cuántos registros desea dar de alta?" << endl;
    cin >> contador;
    for (int i = 0; i < contador; i++)
    {
        cout << "Ingrese número del item: "; // Item es lo mismo que articulo
        cin >> Videojuegos[i].nart;

        cin.ignore();

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

        double iva = 0.16; // Valor del IVA (16%)
        Videojuegos[i].prec += Videojuegos[i].prec * iva; // Se reemplaza el dato del precio y se calcula automaticamente el precio con el IVA
    }
}

void Lista() // Aqui se muestran los articulos dados de alta
{
    string filtroGenero;
    string filtroClasificacion;
    string filtroConsola;

    cin.ignore();

    cout << "Filtro por genero (dejar en blanco para ignorar): "; // Uso de filtros, en caso de querer filtrar se debe de escribir uno de los generos ya dados de alta, en caso de escribir un genero inexstente en la base de datos no se mostrara la Lista, esto sucede con los otros filtros tambien
    getline(cin, filtroGenero);

    cout << "Filtro por clasificacion (dejar en blanco para ignorar): ";
    getline(cin, filtroClasificacion);

    cout << "Filtro por consola (dejar en blanco para ignorar): ";
    getline(cin, filtroConsola);

    cout << "********** LISTA DE ARTICULOS **********" << endl;

    if ((filtroGenero.empty() || Videojuegos[i].gen == filtroGenero) &&
        (filtroClasificacion.empty() || Videojuegos[i].clas == filtroClasificacion) &&
        (filtroConsola.empty() || Videojuegos[i].con == filtroConsola))
    {
        if (Videojuegos[i].status == 'E')
        {
            for (int i = 0; i < contador; i++)
            {
                cout << "Numero de articulo: " << Videojuegos[i].nart << endl;
                cout << "Articulo Eliminado" << endl;
            }
        }
        else
        {
            for (int i = 0; i < contador; i++)
            {
                cout << "Numero de articulo: " << Videojuegos[i].nart << endl;
                cout << "Nombre del articulo: " << Videojuegos[i].art << endl;
                cout << "Descripcion del articulo: " << Videojuegos[i].des << endl;
                cout << "Genero del articulo: " << Videojuegos[i].gen << endl;
                cout << "Clasificacion del articulo: " << Videojuegos[i].clas << endl;
                cout << "Consola del articulo: " << Videojuegos[i].con << endl;
                cout << "Precio del articulo: " << Videojuegos[i].prec << endl;
                cout << "**************************" << endl;
            }
        }
    }
}

void Modificacion() // Aqui se modifican los articulos dados de alta
{
    int numeroArticulo;
    cout << "Ingrese el numero de articulo a modificar: ";
    cin >> numeroArticulo; // El numero del articulo que se pide es el ingresado, tiene que ser de uno de los articulos ya dados de alta

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int indice = -1;
    for (int i = 0; i < contador; i++)
    {
        if (Videojuegos[i].nart == numeroArticulo)
        {
            indice = i;
            break;
        }
    }

    if (indice != -1)
    {
        cout << "Ingrese nuevo nombre del articulo: "; // Se ingresan los nuevos datos nuevamente
        getline(cin, Videojuegos[indice].art);

        cout << "Ingrese nueva descripcion del articulo: ";
        getline(cin, Videojuegos[indice].des);

        cout << "Ingrese nuevo genero del articulo: ";
        getline(cin, Videojuegos[indice].gen);

        cout << "Ingrese nueva clasificacion del articulo: ";
        getline(cin, Videojuegos[indice].clas);

        cout << "Ingrese nueva consola del articulo: ";
        getline(cin, Videojuegos[indice].con);

        cout << "Ingrese nuevo precio del articulo: ";
        cin >> Videojuegos[indice].prec;

        double iva = 0.16; // Valor del IVA (16%)
        Videojuegos[i].prec += Videojuegos[i].prec * iva;

        cout << "Articulo modificado exitosamente." << endl;
    }
    else
    {
        cout << "No se encontró el articulo." << endl;
    }
}

void Baja()
{
    int numeroArticulo;
    cout << "Ingrese el numero de articulo a dar de baja: ";
    cin >> numeroArticulo; // El numero del articulo que se pide es el ingresado, osea, tiene que ser el numero de cualquier articulo ingresado en el codigo. Recomendable checar la lista

    int indice = -1;
    for (int i = 0; i < contador; i++)
    {
        if (Videojuegos[i].nart == numeroArticulo)
        {
            indice = i;
            break;
        }
    }

    if (indice != -1)
    {
        Videojuegos[indice].status = 'E';
        Videojuegos[i].status = 'E';
        cout << "Artículo dado de baja correctamente." << endl;
    }
    else
    {
        cout << "No se encontró el artículo con el número proporcionado." << endl;
    }
}

void Archivo()
{
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo de salida: "; // Una vez ingresado el nombre del archivo no se puede modificar
    cin >> nombreArchivo;

    ofstream archivo(nombreArchivo.c_str(), ios::out | ios::binary);

    if (!archivo)
    {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    archivo << "********** DETALLE DE ARTICULOS **********" << endl;

    if (Videojuegos[i].status == 'E')
    {
        for (int i = 0; i < contador; i++)
        {
            archivo << "Numero de articulo: " << Videojuegos[i].nart << endl;
        }
    }
    else
    {
        for (int i = 0; i < contador; i++)
        {
            archivo << "Numero de articulo: " << Videojuegos[i].nart << endl;
            archivo << "Nombre del articulo: " << Videojuegos[i].art << endl;
            archivo << "Descripcion del articulo: " << Videojuegos[i].des << endl;
            archivo << "Genero del articulo: " << Videojuegos[i].gen << endl;
            archivo << "Clasificacion del articulo: " << Videojuegos[i].clas << endl;
            archivo << "Consola del articulo: " << Videojuegos[i].con << endl;
            archivo << "Precio del articulo: " << Videojuegos[i].prec << endl;
            archivo << "**************************" << endl;
        }
        
    }

    archivo.close();

    cout << "Archivo creado exitosamente." << endl;
}
